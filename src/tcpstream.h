// ----------------------------------------------------------------------------------
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.
// Author: Shihua (Simon) Xiao, sixiao@microsoft.com
// ----------------------------------------------------------------------------------

#define _GNU_SOURCE
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/epoll.h>
#include "const.h"
#include "util.h"
#include "multithreading.h"

int n_read(int fd, char *buffer, size_t total);
int n_write(int fd, const char *buffer, size_t total);
int set_socket_non_blocking(int fd);

void *run_ntttcp_sender_stream( void *ptr );

int ntttcp_server_listen(struct ntttcp_stream_server *ss);
int ntttcp_server_epoll(struct ntttcp_stream_server *ss);
int ntttcp_server_select(struct ntttcp_stream_server *ss);
void *run_ntttcp_receiver_stream( void *ptr );