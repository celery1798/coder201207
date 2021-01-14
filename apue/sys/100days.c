#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>

#define STRSIZE		128

int main(int argc,char *argv[])
{
	time_t stamp;
	struct tm *tm;
	char timestr[STRSIZE];

	time(&stamp);
	tm = localtime(&stamp);	
	/*if error*/	
	strftime(timestr,STRSIZE,"NOW: %Y-%m-%d",tm);
	puts(timestr);

	tm->tm_mday += 100;
	mktime(tm);
	strftime(timestr,STRSIZE,"100 days later: %Y-%m-%d",tm);
	puts(timestr);

	exit(0);
}



