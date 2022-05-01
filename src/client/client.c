#include "client.h"

void sig_handle_c(int signo)
{
    if(signo == SIGINT) //handle SIGINT
    {
        close(cs);  //close open socket
        puts("");   //to maintain terminal allignment
        exit(1);    //terminate process
    }
}

void usage()
{
    printf("./chat-client [SERVER-IP] [SERVER-PORT]\n");    //show usage
}

int init_socket(struct sockaddr_in *sockaddr,char* ip, char* port)
{
    char* pEnd = 0;
    errno = 0;
    uint16_t port_num = strtoul(port,&pEnd,10); //atoi can't detect error
    if(port == pEnd || errno == ERANGE || *pEnd!=0) return -1;  //strtoul failure

    in_addr_t IP = inet_addr(ip);   //transform IP from dot-separated format to 32bit integer
    if(IP == INADDR_NONE) return -1;    //transformation failure

    sockaddr->sin_family = AF_INET; //IPv4
    sockaddr->sin_port = htons(port_num);   //transform port from host order to network order
    (sockaddr->sin_addr).s_addr = IP;

    return 0;
}

void conn_succ_client()
{
    printf("Connected\n");  //client connection success message
}

void chat_client()
{
    uint8_t flag = 1;
    char send_buf[MAX_BUF_LEN] = {0};   //buffer used to send message
    char recv_buf[MAX_BUF_LEN] = {0};   //buffer used to receive message

    while(flag)
    {
        flag = send_msg(cs,send_buf,sizeof(send_buf));  //client sends the message first
        if(flag == 0)
        {
            printf("Disconnected\n");   //flag==0 means QUIT has transmitted
            break;
        }

        flag = recv_msg(cs, recv_buf,sizeof(recv_buf)); //client receives the message after trasmission is completed
        if(flag == 0)
        {
            printf("Disconnected\n");   //flag==0 means QUIT has received
            break;
        }

        //initialize used buffer to prevent misusage of leftover information
        memset(send_buf,0,MAX_BUF_LEN);
        memset(recv_buf,0,MAX_BUF_LEN);
    }
}