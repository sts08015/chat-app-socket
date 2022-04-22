#pragma once

#include "../chat.h"

#define BACKLOG 5

extern int ss;

void sig_handle_s(int signo);
void usage();
int init_socket(struct sockaddr_in *sockaddr,char* port);
void conn_succ_server(struct sockaddr_in* cs_addr);
void chat_server(int cs);
