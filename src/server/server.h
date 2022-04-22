#pragma once

#include "../chat.h"

#define BACKLOG 5

void usage();

void init_socket(struct sockaddr_in *sockaddr,uint16_t port);
