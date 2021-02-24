#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "proto.h"

int main(int argc,char **argv)
{
	struct sockaddr_in raddr;
	struct msg_st sbuf;
	int sd;

	sd = socket(AF_INET,SOCK_DGRAM,0/*IPPROTO_UDP*/);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}


//	bind();

	int val = 1;
	if(setsockopt(sd,SOL_SOCKET,SO_BROADCAST,&val,sizeof(val)) < 0)
	{
		perror("setsockopt()");
		exit(1);
	}


	memset(&sbuf,'\0',sizeof(sbuf));

	sbuf.id = htonl(rand()%100);
	strcpy(sbuf.name,"Alan");
	sbuf.math = htonl(rand()%100);

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET,"255.255.255.255",&raddr.sin_addr);

	if(sendto(sd,&sbuf,sizeof(sbuf),0,(void *)&raddr,sizeof(raddr)) < 0)
	{
		perror("sendto");
		exit(1);
	}

	puts("OK");

	close(sd);

	exit(0);
}












