#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;

void *routine(void *arg)
{
    int flag = 1;
    while (flag)
    {
        if (pthread_mutex_trylock(&mutex))
        {
            printf("Got lock\n");
            sleep(1);
            pthread_mutex_unlock(&mutex);
            flag = 0;
        }
        else
        {
            printf("Didn't get lock\n");
        }
    }
}

int main()
{
    pthread_t tid[4];

    for (int i = 0; i < 4; i++)
    {
        pthread_create(tid + i, NULL, &routine, NULL);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(tid[i], NULL);
    }
}
