#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *func(void *p)
{
	puts("Thread is working.");
//	sleep(1000);
	pthread_exit(NULL);
}


int main()
{
	pthread_t tid;
	int err;

	puts("Begin!");

	err = pthread_create(&tid,NULL,func,NULL);
	if(err)
	{
		fprintf(stderr,"pthread_create():%s\n",strerror(err));
		exit(1);
	}

	pthread_join(tid,NULL);


	puts("End!");
	
//	sleep(1000);

	exit(0);
}


