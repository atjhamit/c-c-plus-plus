#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NO 2

pthread_mutex_t mutexlock;
pthread_barrier_t mutexbarrier;

int value = 0;

void *routing(void *arg)
{
    pthread_mutex_lock(&mutexlock);
    for (int i = 0; i < 100000; i++)
        value += 1;
    pthread_mutex_unlock(&mutexlock);

    return NULL;
}

int main()
{
    pthread_t tid[NO];
    pthread_mutex_init(&mutexlock, NULL);
    pthread_barrier_init(&mutexbarrier, NULL, 3);

    int *ptr;
    int *val = (int *)malloc(sizeof(int));
    *val = 10;

    for (int i = 0; i < NO; i++)
        pthread_create(tid + i, NULL, &routing, val);

    for (int i = 0; i < NO; i++)
        pthread_join(tid[i], (void *)&ptr);

    printf("Final value : %d\n", value);
    return 0;
}