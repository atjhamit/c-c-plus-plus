#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

#define NO 5

int value = 0;
int readCount = 0;

pthread_mutex_t writerMutex;
pthread_mutex_t readMutex;

void *reader(void *args)
{
    int *p = (int *)args;
    while (1)
    {
        pthread_mutex_lock(&readMutex);
        readCount++;

        if (readCount == 1)
            pthread_mutex_lock(&writerMutex);
        pthread_mutex_unlock(&readMutex);

        printf("{Thread : %d} Read value : %d\n", *p, value);

        pthread_mutex_lock(&readMutex);
        readCount--;
        if (readCount == 0)
            pthread_mutex_unlock(&writerMutex);

        pthread_mutex_unlock(&readMutex);
        sleep(1);
    }

    free(p);
    return NULL;
}

void *writer(void *args)
{
    int *p = (int *)args;
    while (1)
    {
        pthread_mutex_lock(&writerMutex);
        value += 10;
        printf("[Thread : %d] Incremented value to %d\n", *p, value);
        pthread_mutex_unlock(&writerMutex);
        sleep(1);
    }
    free(p);
    return NULL;
}

int main()
{
    pthread_t tid[NO];
    pthread_mutex_init(&writerMutex, NULL);
    pthread_mutex_init(&readMutex, NULL);

    for (int i = 0; i < NO; i++)
    {
        int *id = (int *)malloc(sizeof(int));
        *id = i;
        if (i % 2)
        {

            if (pthread_create(tid + i, NULL, &reader, id))
                printf("ERROR creating threads : %d \n", *id);
        }
        else
        {
            if (pthread_create(tid + i, NULL, &writer, id))
                printf("ERROR creating threads : %d \n", *id);
        }
    }

    for (int i = 0; i < NO; i++)
    {
        if (pthread_join(tid[i], NULL))
            printf("Error joining threads : %d \n", i);
    }

    pthread_mutex_destroy(&writerMutex);
    pthread_mutex_destroy(&readMutex);

    return 0;
}