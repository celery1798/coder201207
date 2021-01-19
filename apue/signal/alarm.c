#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>

void alrm_handler(int s)
{
	printf("alrm_handler()\n");
	alarm(1);
}

int main()
{
	signal(SIGALRM,alrm_handler);
	alarm(5);
	alarm(1);
	alarm(3);
		
	while(1);
	{
		printf("while(1)\n");
		sleep(1);
	}

	exit(0);
}





