#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>


int main(int argc,char *argv[])
{
	int a = 123;
	char str[32] = "a1ab23abc";

	printf("%d\n",atoi(str));


	snprintf(str,32,"%d",a);
	puts(str);

	exit(0);
}



