#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

#define NO 10

pthread_mutex_t stoveMutex[4];
int stoveFuel[4] = {100, 100, 100, 100};

void *routine(void *arg)
{
    for (int i = 0; i < 4; i++)
    {
        if (pthread_mutex_trylock(&stoveMutex[i]) == 0)
        {
            int fuelNeeded = (rand()) % 30;
            if ((stoveFuel[i] - fuelNeeded) > 0)
            {
                stoveFuel[i] -= fuelNeeded;
                printf("Fuel left : %d\n", stoveFuel[i]);
                usleep(500000);
            }
            else
            {
                printf("No more fuel left.\n");
            }
            pthread_mutex_unlock(&stoveMutex[i]);
            break;
        }
        else
        {
            printf("No stove available.. waiting ..\n");
            usleep(300000);
            i = 0;
        }
    }
}

int main()
{
    pthread_t tid[NO];
    for (int i = 0; i < 4; i++)
        pthread_mutex_init(&stoveMutex[i], NULL);

    srand(time(NULL));

    for (int i = 0; i < NO; i++)
    {
        if (pthread_create(tid + i, NULL, &routine, NULL))
            printf("Error creating thread : %d\n", i);
    }

    for (int i = 0; i < NO; i++)
    {
        if (pthread_join(tid[i], NULL))
            printf("Error joining thread : %d\n", i);
    }

    for (int i = 0; i < 4; i++)
        pthread_mutex_destroy(&stoveMutex[i]);

    return 0;
}
