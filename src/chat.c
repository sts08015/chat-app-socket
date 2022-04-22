#include "chat.h"

void handleErr(int fd,const char const * msg)
{
    printf("%s\n",msg);
    close(fd);
}

int recv_msg(int fd, char* buf)
{
    recv(fd,buf,sizeof(buf),0);
    fputs(buf,stdout);
    int len = strlen(buf);
    buf[len-1] = 0;
    --len;
    len = len>4?len:4;
    return strncmp(buf,"QUIT",len);
}

int send_msg(int fd, char* buf)
{
    fgets(buf,sizeof(buf),stdin);
    send(fd,buf,sizeof(buf),0);
    int len = strlen(buf);
    buf[len-1] = 0;
    --len;
    len = len>4?len:4;
    return strncmp(buf,"QUIT",len);
}