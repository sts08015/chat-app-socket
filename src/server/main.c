#include "server.h"

int ss; //socket file descriptor for server

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        usage();    //check port has given as an argument
        return -1;
    }

    signal(SIGINT,sig_handle_s);    //assign SIGINT handler

    ss = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);   //open socket
    if(ss < 0)  //socket creation faliure
    {
        perror("socket creation error");    //print error message
        return -1;
    }

    struct sockaddr_in ss_addr = {0};
    int ret = init_socket(&ss_addr,argv[1]);    //initialize server's info
    if(ret < 0) //initializing failed
    {
        handleErr(ss,"socket init error - server"); //print err msg and close socket
        return -1;
    }
    
    ret = bind(ss, (struct sockaddr*) &ss_addr, sizeof(ss_addr));   //allocate IP address and port number
    if(ret < 0) //binding falied
    {
        handleErr(ss,"BindErr");    //print err msg and close socket
        return -1;
    }

    ret = listen(ss,BACKLOG);   //make socket passive and listen to connection requests
    if(ret<0)   //listen failed
    {
        handleErr(ss,"ListenErr");  //print err msg and close socket
        return -1;
    }

    struct sockaddr_in cs_addr = {0};
    socklen_t cs_addr_len = sizeof(cs_addr);

    ret = accept(ss,(struct sockaddr*) &cs_addr,&cs_addr_len);  //accept connection
    if(ret<0)   //accept failed
    {
        handleErr(ss,"AcceptErr");  //print err msg and close socket
        return -1;
    }

    conn_succ_server(&cs_addr); //print connection success string
    chat_server(ret);   //chat with client
    close(ss);  //close socket after chatting is over
    return 0;
}