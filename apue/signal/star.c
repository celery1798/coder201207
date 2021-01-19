#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/*
信号会打断阻塞的系统调用
*/

void int_handler(int s)
{
	write(1,"!",1);
}

int main()
{
	int i;

	signal(SIGINT,int_handler);
//	signal(SIGINT,SIG_IGN);


	for(i = 0  ; i < 10 ; i++)
	{
		write(1,"*",1);
		sleep(1);
	}


	exit(0);
}





