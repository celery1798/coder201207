#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <pwd.h>


int main(int argc,char *argv[])
{
	struct passwd *pwdline;

	if(argc < 2)
	{
		printf("Usage:%s <filenmae>\n",argv[0]);
		exit(0);
	}


	pwdline = getpwuid(atoi(argv[1]));	//"1000"
	if(pwdline == NULL)
	{
		perror("getpwuid()");
		exit(1);
	}
	
	puts(pwdline->pw_name);

	exit(0);
}



