#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>

static int loop = 1;

void alrm_handler(int s)
{
	loop = 0;
}

int main()
{
	long long count = 0;		

	signal(SIGALRM,alrm_handler);
	alarm(5);
		
	while(loop)
		count++;

	printf("%lld\n",count);

	exit(0);
}





