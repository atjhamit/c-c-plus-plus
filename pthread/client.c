#include <sys/socket.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define PORT 8000

int main()
{
    int sockFD = 0;

    struct sockaddr_in serverAddr;
    char *message = "hello from client";
    char buffer[1024] = {0};

    sockFD = socket(AF_INET, SOCK_STREAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    connect(sockFD, (struct sockaddr *)&serverAddr, sizeof(serverAddr));

    send(sockFD, message, strlen(message), 0);
    read(sockFD, buffer, 1024);
    printf("%s\n", buffer);
    return 0;
}