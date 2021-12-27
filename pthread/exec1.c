#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("Entered exec1 \n");

    char *args[] = {"Hey ", "there ", "you!", NULL};
    execv("sudo ./exec2", args);

    printf("Exited exec1 \n");
}