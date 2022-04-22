#include "server.h"

int ss;

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        usage();
        return -1;
    }

    signal(SIGINT,sig_handle_s);

    ss = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
    if(ss < 0){
        perror("socket creation error");
        return -1;
    }

    struct sockaddr_in ss_addr = {0};
    int ret = init_socket(&ss_addr,argv[1]);
    if(ret < 0){
        handleErr(ss,"socket init error - server");
        return -1;
    }
    
    ret = bind(ss, (struct sockaddr*) &ss_addr, sizeof(ss_addr));
    if(ret < 0){
        handleErr(ss,"BindErr");
        return -1;
    }

    ret = listen(ss,BACKLOG);
    if(ret<0){
        handleErr(ss,"ListenErr");
        return -1;
    }

    struct sockaddr_in cs_addr = {0};
    socklen_t cs_addr_len = sizeof(cs_addr);

    ret = accept(ss,(struct sockaddr*) &cs_addr,&cs_addr_len);
    if(ret<0){
        handleErr(ss,"AcceptErr");
        return -1;
    }

    conn_succ_server(&cs_addr);
    chat_server(ret);
    close(ss);

    return 0;
}