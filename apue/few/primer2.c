#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


#define LEFT    30000000
#define RIGHT   30000200

int main()
{
	pid_t pid;
	int i,flag = 1,j;

	for(i = LEFT; i <= RIGHT; i++)
	{
		pid = fork();
		if(pid < 0)
		{
			perror("fork()");
			exit(1);
		}

		if(pid == 0)		//child
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
				printf("%d is a primer.\n",i);
//			sleep(10);
			exit(0);	
		}	
	}

	int st;
	for(i = LEFT; i <= RIGHT; i++)
		wait(NULL);
/*
	{
		wait(&st);
		if(WIFEXITED(st))
			printf("CODE:%d!",WEXITSTATUS(st));
		else
		{
			WIFSIGNALED(st)
		
		}
	}


*/


	exit(0);
}

