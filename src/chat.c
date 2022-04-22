#include "chat.h"

void handlePortErr(int fd)
{
    printf("PORT-NUM ERR\n");
    close(fd);
}

void handleBindErr(int fd)
{
    printf("BIND ERR\n");
    close(fd);
}

void handleListenErr(int fd)
{
    printf("LISTEN ERR\n");
    close(fd);
}

void handleAcceptErr(int fd)
{
    printf("ACCEPT ERR\n");
    close(fd);
}