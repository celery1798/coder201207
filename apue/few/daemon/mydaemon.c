#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int mydaemon_init()
{
	pid_t pid;
	int fd;

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		return -1;
	}

	if(pid > 0)
		exit(0);

	//child
	
	//close(0);
	//close(1);
	//close(2);

	//0->/tmp/in   1->/tmp/out    2->/tmp/err

	fd = open("/dev/null",O_RDWR);
	if(fd < 0)
	{
		perror("open()");
		return -2;
	}

	dup2(fd,0);
	dup2(fd,1);
	dup2(fd,2);
	if(fd > 2)
		close(fd);

	setsid();

	chdir("/");
	umask(0);

	return 0;
}

int main()
{
	FILE *fp;
	int i;

	if(mydaemon_init())
	{
		printf("mydaemon_init() error.\n");
		exit(1);
	}
	else
		printf("mydaemon_init() succeed\n");

	/*do sth*/	

	fp = fopen("/tmp/mydaemon.log","w");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	for(i = 0 ; ; i++)
	{
		fprintf(fp,"%d\n",i);
		fflush(fp);
		sleep(1);
	}

	fclose(fp);

	exit(0);
}



