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
    printf("Waiting at the barrier.\n");
    pthread_barrier_wait(&barrier);
    printf("Crossed the barrier.\n");
    return NULL;
}

int main()
{
    pthread_t tid[NO];
    pthread_barrier_init(&barrier, NULL, 3);

    for (int i = 0; i < NO; i++)
        pthread_create(&tid[i], NULL, &routine, NULL);

    for (int i = 0; i < NO; i++)
        pthread_detach(tid[i]);

    pthread_exit(0);
    for (int i = 0; i < NO; i++)
        if (pthread_join(tid[i], NULL))
            printf("Error joining. \n");

    pthread_barrier_destroy(&barrier);
    return 0;
}