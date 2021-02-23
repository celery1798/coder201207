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
	struct msg_st *sbuf;
	int sd,size;

	if(argc < 3)
	{
		fprintf(stderr,"Usage...\n");
		exit(1);	
	}

	if(strlen(argv[2]) > NAMEMAX)
	{
		fprintf(stderr,"Name is too long.\n");
		exit(1);
	}
	
	size = sizeof(struct msg_st) + strlen(argv[2]) + 1;

	sbuf = malloc(size);
	if(sbuf == NULL)
	{
		fprintf(stderr,"malloc() error.\n");
		exit(2);
	}


	sd = socket(AF_INET,SOCK_DGRAM,0/*IPPROTO_UDP*/);
	if(sd < 0)
	{
		perror("socket()");
		exit(1);
	}


//	bind();

	sbuf->id = htonl(rand()%100);
	strcpy(sbuf->name,argv[2]);
	sbuf->math = htonl(rand()%100);

	raddr.sin_family = AF_INET;
	raddr.sin_port = htons(atoi(RCVPORT));
	inet_pton(AF_INET,argv[1],&raddr.sin_addr);

	if(sendto(sd,sbuf,size,0,(void *)&raddr,sizeof(raddr)) < 0)
	{
		perror("sendto");
		exit(1);
	}

	puts("OK");

	close(sd);
	free(sbuf);

	exit(0);
}












