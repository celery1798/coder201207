#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void int_handler(int s)
{
	write(1,"!",1);
}

int main()
{
	int i;
	sigset_t set,oset,tmpset;

	signal(SIGINT,int_handler);
	sigemptyset(&set);
	sigaddset(&set,SIGINT);

	sigprocmask(SIG_BLOCK,&set,&oset);

	while(1)		// 100 times
	{

		for(i = 0  ; i < 5 ; i++)
		{
			write(1,"*",1);
			sleep(1);
		}
		write(1,"\n",1);
/*
		sigprocmask(SIG_SETMASK,&oset,&tmpset);
		pause();
		sigprocmask(SIG_SETMASK,&tmpset,NULL);
*/
		sigsuspend(&oset);

	}
	exit(0);
}





