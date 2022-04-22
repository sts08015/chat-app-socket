#include "server.h"

void sig_handle_s(int signo)
{
    if(signo == SIGINT)
    {
        close(ss);
        puts("");
        exit(1);
    }
}

void usage()
{
    printf("./chat-server [PORT-NUM]\n");
}

int init_socket(struct sockaddr_in *sockaddr,char* port)
{
    char* pEnd = 0;
    errno = 0;
    uint16_t port_num = strtoul(port,&pEnd,10); //atoi can't detect error
    if(port == pEnd || errno == ERANGE || *pEnd!=0) return -1;
    sockaddr->sin_family = AF_INET;
    sockaddr->sin_port = htons(port_num);
    (sockaddr->sin_addr).s_addr = htonl(INADDR_ANY);

    return 0;
}

void conn_succ_server(struct sockaddr_in* cs_addr)
{
    uint16_t port = ntohs(cs_addr->sin_port);
    char* ip = inet_ntoa(cs_addr->sin_addr);
    printf("Connection from %s:%hu\n",ip,port);
}

void chat_server(int cs)
{
    uint8_t flag = 1;
    char send_buf[MAX_BUF_LEN] = {0};
    char recv_buf[MAX_BUF_LEN] = {0};
    
    while(flag)
    {
        int s = recv(cs,recv_buf,sizeof(recv_buf),0);
        //printf("%d\n",s);
        fputs(recv_buf,stdout);
        int len = strlen(recv_buf);
        len = len>4?len:4;
        if(strncmp(recv_buf,"QUIT",len) == 0){
            flag = 0;
            printf("Disconnected\n");
        }

    }
}
