#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NO 10

pthread_mutex_t mutexfuel;
pthread_barrier_t mutexbarrier;

int fuel = 0;

void *routing(void *arg)
{
    pthread_mutex_lock(&mutexfuel);
    pthread_mutex_lock(&mutexfuel);
    fuel += 50;
    printf("Incremented fuel to %d\n", fuel);
    pthread_mutex_unlock(&mutexfuel);
    pthread_mutex_unlock(&mutexfuel);
    return NULL;
}

int main()
{
    pthread_t tid[NO];
    pthread_mutexattr_t mutexattr;
    pthread_mutexattr_init(&mutexattr);
    pthread_mutexattr_settype(&mutexattr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutexfuel, &mutexattr);
    // pthread_barrier_init(&mutexbarrier, NULL, 3);

    for (int i = 0; i < NO; i++)
        pthread_create(tid + i, NULL, &routing, NULL);

    for (int i = 0; i < NO; i++)
        pthread_join(tid[i], NULL);

    printf("Fuel : %d\n", fuel);
    pthread_mutex_destroy(&mutexfuel);
    pthread_mutexattr_destroy(&mutexattr);
    return 0;
}