#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	pid_t pid;

	puts("Begin");


	fflush(NULL);			/*!!!*/

	pid = fork();
	if(pid < 0)
	{
		perror("fork()");
		exit(2);
	}
	if(pid == 0)
	{
		execl("/bin/date","date","+%s",NULL);
		perror("execl()");
		exit(1);
	}

	wait(NULL);
	puts("End");

	exit(0);

}





