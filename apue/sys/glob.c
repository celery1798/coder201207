#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <glob.h>

#define PAT		"/etc/a*.conf"

int main(int argc,char *argv[])
{
	glob_t globres;
	int err,i;

	err = glob(PAT,0,NULL,&globres);
	if(err)
	{
		printf("ERROR:%d\n",err);
		exit(0);		
	}

	for(i = 0 ; i < globres.gl_pathc; i++)
		puts(globres.gl_pathv[i]);

	globfree(&globres);

	exit(0);
}



