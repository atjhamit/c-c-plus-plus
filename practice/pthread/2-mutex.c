#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

#define N 3

pthread_mutex_t mutex;

int sharedval = 0;

void* routine(void* arg)
{

    int* abc = (int*) arg;
    printf("Inside thread : %d\n", *abc);

    pthread_mutex_lock(&mutex);
    sharedval++;
    pthread_mutex_unlock(&mutex);

    return (void*) abc;
}

int main()
{
    printf("Spinning threads\n");
    pthread_t tid[N];
    pthread_mutex_init(&mutex,NULL);

    for(int i = 0; i < N; i++)
    {
        int* ival = (int*) malloc(sizeof(int));
        *ival = i;
        pthread_create(tid + i,NULL,&routine, ival);
    }

    int* val;

    for(int i = 0; i < N; i++)
    {
        pthread_join(tid[i], (void*) &val);
        printf("Joining thread %d, value : %d\n", i, *val);
    }

    pthread_mutex_destroy(&mutex);
    printf("Exiting main; sharedval : %d\n",sharedval);
    return 0;
}
