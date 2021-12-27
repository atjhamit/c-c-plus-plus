#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Entered exec2 \n");

    printf("Message==\n%s \t %s \t %s\n", argv[1], argv[2], argv[3]);

    printf("Exited exec2 \n");
}