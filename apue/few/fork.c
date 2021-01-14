#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/* 
不要猜测或假设父子进程中哪个进程先进行，由调度器的调度策略决定

*/

int main()
{
	pid_t pid;

	printf("[%d]Begin",getpid());


	fflush(NULL);		/*!!!*/


	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(1);
	}

	if(pid == 0)	//child
	{
		printf("[%d]Child is working\n",getpid());
	}
	else		//pid > 0  parent
	{
		printf("[%d]Parent is working\n",getpid());
	}

	printf("[%d]End\n",getpid());


//	sleep(1000);

	exit(0);

}





