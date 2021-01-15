#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define N		3
#define LEFT    30000000
#define RIGHT   30000200

int main()
{
	pid_t pid;
	int i,n,flag = 1,j;

	for(n = 0 ; n < N ; n++)
	{
		pid = fork();
		if(pid < 0)
		{
			perror("fork()");
			exit(1);
		}

		if(pid == 0)		//child
		{
			for(i = LEFT+n; i <= RIGHT; i+=N)
			{
				flag = 1;
				for(j = 2; j <= i/2 ; j++ )
				{
					if(i % j == 0)
					{
						flag = 0;
						break;
					}
				}

				if(flag)
					printf("[%d]%d is a primer.\n",n,i);
				//			sleep(10);
			
			}	
			exit(0);
		}
	}

	for(n = 0 ; n < N ; n++)
		wait(NULL);

	exit(0);
}

