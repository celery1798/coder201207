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


#define MEMSIZE		1024

int main(int argc,char *argv[])
{
	char *str;
	pid_t pid;
	
	str = mmap(NULL,MEMSIZE,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
	if(str == MAP_FAILED)
	{
		perror("mmap()");
		exit(1);
	}


	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)	// child write
	{
		strcpy(str,"HELLO!");
		munmap(str,MEMSIZE);
		exit(0);
	}
	else		// parent read
	{
		wait(NULL);
		puts(str);
		munmap(str,MEMSIZE);
		exit(0);

	}

}














