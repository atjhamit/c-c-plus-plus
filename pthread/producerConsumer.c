#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>

#define NO 8

pthread_mutex_t mutexlock;

int buffer[10];
int counter = 0;

sem_t emptySlot;
sem_t filledSlot;

void *producer(void *args)
{
    while (1)
    {
        sem_wait(&emptySlot);
        pthread_mutex_lock(&mutexlock);
        int x = rand() % 100;
        printf("Produced value : %d\n", x);
        buffer[counter] = x;
        counter++;
        pthread_mutex_unlock(&mutexlock);
        sem_post(&filledSlot);
        sleep(3);
    }
}

void *consumer(void *args)
{
    while (1)
    {
        sem_wait(&filledSlot);
        pthread_mutex_lock(&mutexlock);
        int y = buffer[counter - 1];
        printf("Consumed value : %d\n", y);
        counter--;
        pthread_mutex_unlock(&mutexlock);
        sem_post(&emptySlot);
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    pthread_t tid[NO];
    srand(time(NULL));
    pthread_mutex_init(&mutexlock, NULL);
    sem_init(&emptySlot, 0, 10);
    sem_init(&filledSlot, 0, 0);

    for (int i = 0; i < NO; i++)
    {
        if (i % 2)
        {
            if (pthread_create(tid + i, NULL, &producer, NULL))
                perror("Error creating thread.");
        }
        else
        {
            if (pthread_create(tid + i, NULL, &consumer, NULL))
                perror("Error creating thread.");
        }
    }

    for (int i = 0; i < NO; i++)
    {
        if (pthread_join(tid[i], NULL))
            perror("Error joining thread.");
    }

    pthread_mutex_destroy(&mutexlock);
    sem_destroy(&emptySlot);
    sem_destroy(&filledSlot);
    return 0;
}