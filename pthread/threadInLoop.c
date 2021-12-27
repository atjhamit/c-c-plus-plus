#include <stdio.h>
#include <malloc.h>
#include <pthread.h>

#define LOG(x) printf("%d\n", x);
int vec[10] = { 1,2,3,4,5,6,7,8,9,10 };
#define NO 10

void* routine(void* arg)
{
	int* index = (int*)arg;
	LOG(vec[*index]);
	free(index);
	return NULL;
}

int main()
{
	pthread_t tid[NO];

	for (int i = 0; i < NO; i++)
	{
		int* index = (int*)malloc(sizeof(int));
		*index = i;
		pthread_create(tid + i, NULL, &routine, index);
	}

	for (int i = 0; i < NO; i++)
	{
		pthread_join(tid[i], NULL);
	}

	return 0;
}
