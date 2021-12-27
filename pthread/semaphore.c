
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define NO 10

sem_t sema;

void *routine(void *arg)
{
    sem_wait(&sema);
    sleep(1);
    int *p = (int *)arg;
    printf("Thread id : %d\n", *p);
    sem_post(&sema);
    free(p);
    return 0;
}

int main()
{
    pthread_t tid[NO];
    sem_init(&sema, 0, 2);

    for (int i = 0; i < NO; i++)
    {
        int *a = (int *)malloc(sizeof(int));
        *a = i;
        pthread_create(tid + i, NULL, &routine, a);
    }

    for (int i = 0; i < NO; i++)
        pthread_join(tid[i], NULL);

    sem_destroy(&sema);
    return 0;
}