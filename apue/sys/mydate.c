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
	char fmtstr[STRSIZE] = {'\0'};
	int ch;
	FILE *fp = stdout;

	time(&stamp);
	tm = localtime(&stamp);	
	/*if error*/	


	//  ./a.out  -H  -m /tmp/out -y 4
	//      0     1   2    3    optind

	while(1)
	{

		ch = getopt(argc,argv,"-y:mdH:MS");
		if(ch < 0)
			break;

		switch(ch)
		{
			case 1:
				if(fp == stdout)
				{
					fp = fopen(argv[optind-1],"w");
					if(fp == NULL)
					{
						perror("fopen()");	
						fp = stdout;
					}
				}
				break;
			case 'y':
				if(strcmp(optarg,"2") == 0)
					strncat(fmtstr,"%y ",STRSIZE);
				else if(strcmp(optarg,"4") == 0)
						strncat(fmtstr,"%Y ",STRSIZE);
					 else
					 	printf("Invalid argument of -y\n");
				break;
			case 'm':
				strncat(fmtstr,"%m ",STRSIZE);
				break;
			case 'd':
				strncat(fmtstr,"%d ",STRSIZE);
				break;
			case 'H':
				if(strcmp(optarg,"12") == 0)
					strncat(fmtstr,"%I(%P) ",STRSIZE);
				else if(strcmp(optarg,"24") == 0)
					strncat(fmtstr,"%H ",STRSIZE);
				else
					printf("Invalid argument of -H\n");

				break;
			case 'M':
				strncat(fmtstr,"%M ",STRSIZE);
				break;
			case 'S':
				strncat(fmtstr,"%S ",STRSIZE);
				break;
			default:
				break;

		}
	}

	strncat(fmtstr,"\n",STRSIZE);
	strftime(timestr,STRSIZE,fmtstr,tm);
	fputs(timestr,fp);

	if(fp != stdout)
		fclose(fp);

	exit(0);
}



