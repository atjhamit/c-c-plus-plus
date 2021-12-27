#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8000

int main()
{
    int serverFD, clientFD, newsocket;
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    char buffer[1024] = {0};
    char *reply = "hey there from server";

    int addrlen = sizeof(address);

    if ((serverFD = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Error in creating socket");
    }

    if (bind(serverFD, (struct sockaddr_in *)&address, sizeof(address)) < 0)
        printf("Error in binding .");

    if (listen(serverFD, 3) < 0)
        printf("error in listening.");

    while (1)
    {
        if ((newsocket = accept(serverFD, (struct sockaddr_in *)&address, (socklen_t *)&addrlen)) < 0)
            printf("error accepting");

        read(newsocket, buffer, 1024);
        printf("value read : %s\n", buffer);

        send(newsocket, reply, strlen(reply), 0);
    }

    return 0;
}