#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NO 10

pthread_mutex_t mutex;
pthread_barrier_t barrier;

sem_t sema;

int counter = 0;

void *routine(void *args)
{
    int *tid = (int *)args;
    sem_wait(&sema);
    printf("thread id : %d\n", *tid);
    // printf("Hey there!!\n");
    free(tid);
    sleep(1);
    sem_post(&sema);
    return NULL;
}

int main()
{
    pthread_t tid[NO];
    sem_init(&sema, 0, 5);

    int *res;

    for (int i = 0; i < NO; i++)
    {
        int *tno = malloc(sizeof(int));
        *tno = i;
        if (pthread_create(tid + i, NULL, &routine, tno))
            printf("Error creating thread : %d\n", *tno);
    }

    for (int i = 0; i < NO; i++)
    {
        if (pthread_join(tid[i], (void *)&res))
            printf("Error joining thread : %d\n", i);
    }

    sem_destroy(&sema);
    printf("Counter : %d\n", counter);
}