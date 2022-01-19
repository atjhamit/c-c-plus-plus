#include <string.h>
#include <stdio.h>

void mymemcpy(void* source, void *destination, size_t t)
{
    char* src = (char *) source;
    char* dest = (char *) destination;
    int index = 0;

    for(; index < t; index++)
    {
        dest[index] = src[index];
    }
}

int main()
{
    char src[] = "hey there";
    char dest[100];

    mymemcpy(src, dest, strlen(src)+1); 
    printf("Source : %s\n", src);
    printf("Destination : %s\n", dest);
    return 0;
}
