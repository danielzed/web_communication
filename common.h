#ifndef CHATROOM_COMMON_H
#define CHATROOM_COMMON_H

#include <iostream>
#include <list>
#include <sys/types>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define EPOLL_SIZE 5000
#define BUF_SIZE 0XFFFF
#define SERVER_WELCOM "welcome to chatroom"
#define SERVER_MESSAGE "clientid %D say >> %s"
#define EXIT "EXIT"
#define CAUTION "you are the only on in the chatroom"

static void addfd(int epollfd, int fd, bool enable_et)
{
	struct epoll_event ev;
	ev.data.fd = fd;
	ev.events = EPOLLIN;
	if(enable_et)
		ev.events = EPOLLIN | EPOLLET;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
	fcntl(fd,F_SETFL, fcntl(fd,F_GETFD,0)|O_NONBLOCK);
	printf("fd added to epoll!\n\n");
}

#endif