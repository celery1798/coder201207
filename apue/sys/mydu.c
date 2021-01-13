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

#define PATHSIZE	256

int path_noloop(const char *path)
{//  /etc/xxx   sys/abc  sys/.  sys/.a.
	char *pos;

	pos = strrchr(path,'/');

	if(strcmp(pos+1,".") == 0 || strcmp(pos+1,"..") == 0)
		return 0;
	return 1;
}

int64_t mydu(const char *path)
{
	int i;
	glob_t globres;
	struct stat statres;
	char nextpath[PATHSIZE];
	int64_t sum = 0;

	if(lstat(path,&statres) < 0)
	{
		perror("lstat()");
		exit(1);
	}

	if(!S_ISDIR(statres.st_mode))	
		return statres.st_blocks;

	//dir  path ->  /etc
	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/*",PATHSIZE);
	glob(nextpath,0,NULL,&globres);
	/*if error*/

	strncpy(nextpath,path,PATHSIZE);
	strncat(nextpath,"/.*",PATHSIZE);
	glob(nextpath,GLOB_APPEND,NULL,&globres);
	/*if error*/

	for(i = 0 ; i < globres.gl_pathc; i++)
	{
		if(path_noloop(globres.gl_pathv[i]))
			sum += mydu(globres.gl_pathv[i]);
	}

	sum += statres.st_blocks;	

	return sum;
}


int main(int argc,char *argv[])
{

	if(argc < 2)
	{
		printf("Usage:%s <filenmae>\n",argv[0]);
		exit(0);
	}

	printf("%lld\n",(long long)mydu(argv[1])/2);


	exit(0);
}



