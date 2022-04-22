#pragma once

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void handlePortErr(int fd);
void handleBindErr(int fd);
void handleListenErr(int fd);
void handleAcceptErr(int fd);