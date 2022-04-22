#include "client.h"

int cs;

int main(int argc, char* argv[])
{
    if(argc!=3){
        usage();
        return -1;
    }

    signal(SIGINT,sig_handle_c);

    cs = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(cs < 0){
        perror("socket creation error");
        return -1;
    }
    
    struct sockaddr_in ss_addr = {0};
    int ret = init_socket(&ss_addr,argv[1],argv[2]);
    if(ret<0){
        handleErr(cs, "socket init error - client");
        return -1;
    }

    ret = connect(cs,(struct sockaddr*) &ss_addr,sizeof(ss_addr));
    if(ret<0){
        handleErr(cs,"connect error");
        return -1;
    }
    
    conn_succ_client();
    chat_client();

    close(cs);
    return 0;
}