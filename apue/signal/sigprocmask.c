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
	sigset_t set,oset;

	signal(SIGINT,int_handler);
	sigemptyset(&set);
	sigaddset(&set,SIGINT);

	while(1)		// 100 times
	{
//		sigprocmask(SIG_BLOCK,&set,NULL);
		sigprocmask(SIG_BLOCK,&set,&oset);

		for(i = 0  ; i < 5 ; i++)
		{
			write(1,"*",1);
			sleep(1);
		}
		write(1,"\n",1);
		
//		sigprocmask(SIG_UNBLOCK,&set,NULL);
		sigprocmask(SIG_SETMASK,&oset,NULL);

	}
	exit(0);
}





