#include "chat.h"

void handleErr(int fd,const char const * msg)
{
    printf("%s\n",msg);
    close(fd);
}

int recv_msg(int fd, char* buf,int maxlen)
{
    recv(fd,buf,maxlen,0);
    fputs(buf,stdout);
    int len = strlen(buf);
    buf[len-1] = 0;
    --len;
    len = len>4?len:4;
    return strncmp(buf,"QUIT",len);
}

int send_msg(int fd, char* buf, int maxlen)
{
    fgets(buf,maxlen,stdin);
    send(fd,buf,maxlen,0);
    int len = strlen(buf);
    buf[len-1] = 0;
    --len;
    len = len>4?len:4;
    return strncmp(buf,"QUIT",len);
}