#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <signal.h>


int main()
{
	time_t end;
	long long count = 0;		

	end = time(NULL)+5;
		
	while(time(NULL) <= end)
		count++;

	printf("%lld\n",count);

	exit(0);
}





