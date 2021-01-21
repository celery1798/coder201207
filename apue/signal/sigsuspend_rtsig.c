#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define MYRTSIG		SIGRTMIN+6

void rt_handler(int s)
{
	write(1,"!",1);
}

int main()
{
	int i;
	sigset_t set,oset,tmpset;

	signal(MYRTSIG,rt_handler);
	sigemptyset(&set);
	sigaddset(&set,MYRTSIG);

	sigprocmask(SIG_BLOCK,&set,&oset);

	while(1)		// 100 times
	{

		for(i = 0  ; i < 5 ; i++)
		{
			write(1,"*",1);
			sleep(1);
		}
		write(1,"\n",1);
		sigsuspend(&oset);

	}
	exit(0);
}





