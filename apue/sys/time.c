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

#define BUFSIZE		128
#define FNAME		"timelog.txt"

int main(int argc,char *argv[])
{
	FILE *fp;
	int no = 0;
	time_t stamp;
	struct tm *tm;
	char buf[BUFSIZE];

	
	fp = fopen(FNAME,"a+");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	while(fgets(buf,BUFSIZE,fp) != NULL)
		no++;

	while(1)
	{
		stamp = time(NULL);
		tm = localtime(&stamp);	
		/*if error*/		
		fprintf(fp,"%d %d-%d-%d %d:%d:%d\n",++no,tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour, tm->tm_min,tm->tm_sec);

		fflush(fp);
		sleep(1);
	}
	
	fclose(fp);

	exit(0);
}



