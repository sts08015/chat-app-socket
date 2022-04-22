#pragma once
#include "../chat.h"

extern int cs;

void sig_handle_c(int signo);
void usage();
int init_socket(struct sockaddr_in *sockaddr,char* ip, char* port);
void conn_succ_client();
void chat_client();