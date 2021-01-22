#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define THRNUM	20	
#define FNAME	"/tmp/count.txt"
#define LINEBUFSIZE	1024

static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

void *thr_add(void *p)
{
	FILE *fp;
	char linebuf[LINEBUFSIZE];

	fp = fopen(FNAME,"r+");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(1);
	}

	pthread_mutex_lock(&mut);

	fgets(linebuf,LINEBUFSIZE,fp);
	/*if error*/
	fseek(fp,0,SEEK_SET);
//	sleep(1);
	fprintf(fp,"%d\n",atoi(linebuf)+1);	
	fclose(fp);

	pthread_mutex_unlock(&mut);

	pthread_exit(NULL);
}

int main()
{
	int i,err;
	pthread_t tid[THRNUM];

	for(i = 0; i < THRNUM; i++)
	{
		err = pthread_create(tid+i,NULL,thr_add,NULL);
		if(err)
		{
			fprintf(stderr,"pthread_create():%s\n",strerror(err));
			exit(1);
		}

	}

	for(i = 0; i < THRNUM; i++)
		pthread_join(tid[i],NULL);

	pthread_mutex_destroy(&mut);

	exit(0);
}



