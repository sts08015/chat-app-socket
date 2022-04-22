#include "chat.h"

void handleErr(int fd,const char const * msg)
{
    printf("%s\n",msg);
    close(fd);
}