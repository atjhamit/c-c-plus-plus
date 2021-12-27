#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int value;
pthread_mutex_t mutex;

void* routine(void* arg)
{
    for(int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        value++;
        pthread_mutex_unlock(&mutex);
    }
}


int main()
{

    pthread_t threads[4];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < 4; i++)
    {
        printf("Creating thread\n");
        pthread_create(&threads[i], NULL, &routine,NULL);
    }
    for(int i = 0; i < 4; i++) 
    {
        pthread_join(threads[i], NULL);
        printf("Joining thread\n");
    }

    printf("value : %d\n", value);
    return 0;
}

