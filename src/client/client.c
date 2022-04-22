#include "client.h"

void sig_handle_c(int signo)
{
    if(signo == SIGINT)
    {
        close(cs);
        puts("");
        exit(1);
    }
}

void usage()
{
    printf("./chat-client [SERVER-IP] [SERVER-PORT]\n");
}

int init_socket(struct sockaddr_in *sockaddr,char* ip, char* port)
{
    char* pEnd = 0;
    errno = 0;
    uint16_t port_num = strtoul(port,&pEnd,10); //atoi can't detect error
    if(port == pEnd || errno == ERANGE || *pEnd!=0) return -1;

    in_addr_t IP = inet_addr(ip);
    if(IP == INADDR_NONE) return -1;

    sockaddr->sin_family = AF_INET;
    sockaddr->sin_port = htons(port_num);
    (sockaddr->sin_addr).s_addr = IP;
}

void conn_succ_client()
{
    printf("Connected\n");
}

void chat_client(int ss)
{
    uint8_t flag = 1;
    char send_buf[MAX_BUF_LEN] = {0};
    char recv_buf[MAX_BUF_LEN] = {0};

    while(flag)
    {
        fgets(send_buf,sizeof(send_buf),stdin);
        int len = strlen(send_buf);
        send_buf[len-1] = 0;
        send(ss,send_buf,sizeof(send_buf),0);
        
        len = len>4?len:4;
        if(strncmp(send_buf,"QUIT",len) == 0)
        {
            flag = 0;
            printf("Disconnected\n");
        }
    }
}