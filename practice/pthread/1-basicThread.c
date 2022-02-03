#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define N 3

void* routine(void* arg)
{
    int* abc = (int*) arg;
    printf("Inside thread : %d\n", *abc);
    return (void*) abc;
}

int main()
{
    printf("Spinning threads\n");
    pthread_t tid[3];

    for(int i = 0; i < N; i++)
    {
        int* ival = (int*) malloc(sizeof(int));
        *ival = i;
        pthread_create(tid + i,NULL,&routine, ival);
    }

    int* val;

    for(int i = 0; i < N; i++)
    {
        pthread_join(tid[i], (void*)&val);
        printf("Joining thread %d, value : %d\n", i, *val);
    }

    printf("Exiting main\n");
    return 0;
}
