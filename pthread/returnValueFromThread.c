#include <pthread.h>
#include <unistd.h>
#include <malloc.h>
#include <stdio.h>
#include <time.h>

void *func(void *arg)
{
    int value = (rand() % 6) + 1;
    int *result = (int *)malloc(sizeof(int));
    printf("Value in thread : %d\n", value);
    *result = value;
    return (void *)result;
}

int main()
{
    pthread_t tid1;
    pthread_create(&tid1, 0, &func, 0);

    int *result;
    pthread_join(tid1, (void *)&result);
    printf("Value in main : %d\n", *result);
    free(result);
    return 0;
}
