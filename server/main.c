#include "server.h"

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        usage();
        return -1;
    }

    int ss = socket(PF_INET,SOCK_STREAM,0);
    if(ss == -1) perror("socket creation error");


    return 0;
}