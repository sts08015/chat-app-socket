#pragma once

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_LEN 200

void handleErr(int fd,const char const* msg);
int recv_msg(int fd, char* buf);
int send_msg(int fd, char* buf);