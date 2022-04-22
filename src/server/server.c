#include "server.h"

void usage()
{
    printf("./chat-server [PORT-NUM]\n");
}

void init_socket(struct sockaddr_in *sockaddr,uint16_t port)
{
    sockaddr->sin_family = AF_INET;
    sockaddr->sin_port = htons(port);
    (sockaddr->sin_addr).s_addr = htonl(INADDR_ANY);
}
