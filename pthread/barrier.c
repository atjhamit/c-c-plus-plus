#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

#define NO 3

pthread_barrier_t barrier;

void *routine(void *arg)
{
    pthread_t id = pthread_self();
    printf("Waiting at the barrier.\n");
    pthread_barrier_wait(&barrier);
    printf("Crossed the barrier.\n");
    printf("My id : %lul\n", id);
    return NULL;
}

int main()
{
    pthread_t tid[NO];
    pthread_barrier_init(&barrier, NULL, 3);

    for (int i = 0; i < NO; i++)
        pthread_create(&tid[i], NULL, &routine, NULL);

    for (int i = 0; i < NO; i++)
        pthread_join(tid[i], NULL);

    pthread_barrier_destroy(&barrier);
    return 0;
}