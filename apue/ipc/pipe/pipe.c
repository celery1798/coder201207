#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFSIZE	 1024


int main(int argc,char *argv[])
{
	pid_t pid;
	char buf[BUFSIZE];
	int pd[2];
		
	if(pipe(pd) < 0)
	{
		perror("pipe()");
		exit(1);
	}
		
	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)	// child read
	{
		close(pd[1]);
		read(pd[0],buf,BUFSIZE);
		/*if error*/
		puts(buf);
		close(pd[0]);
		exit(1);
	}
	else		// parent write
	{
		close(pd[0]);
		write(pd[1],"HELLO!",6);
		close(pd[1]);
		wait(NULL);
		exit(0);

	}

}














