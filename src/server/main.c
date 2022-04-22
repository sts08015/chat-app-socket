#include "server.h"

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        usage();
        return -1;
    }

    int ss = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(ss < 0) perror("socket creation error");

    char* pEnd = 0;
    errno = 0;
    uint16_t port = strtoul(argv[1],&pEnd,10); //atoi can't detect error
    if(argv[1] == pEnd || errno == ERANGE || *pEnd!=0){
        handlePortErr(ss);
        return -1;
    }

    struct sockaddr_in ss_addr = {0};
    init_socket(&ss_addr,port);
    int ret = bind(ss, (struct sockaddr*) &ss_addr, sizeof(ss_addr));
    if(ret < 0){
        handleBindErr(ss);
        return -1;
    }

    ret = listen(ss,BACKLOG);
    if(ret<0){
        handleListenErr(ss);
        return -1;
    }

    struct sockaddr_in cs_addr = {0};
    socklen_t cs_addr_len = sizeof(cs_addr);

    ret = accept(ss,(struct sockaddr*) &cs_addr,&cs_addr_len);
    if(ret<0){
        handleAcceptErr(ss);
        return -1;
    }

    close(ss);

    return 0;
}