#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>

void *routine(void *arg)
{
    int *p = (int *)arg;
    printf("value from main : %d\n", *p);
    *p += 10;

    pthread_exit((void *)p);
}

int main()
{
    pthread_t tid;
    int *val = (int *)malloc(sizeof(int));
    *val = 10;

    pthread_create(&tid, NULL, &routine, val);

    // pthread_exit(0);

    int *result;
    pthread_join(tid, (void *)&result);

    printf("value from routine : %d\n", *result);

    return 0;
}