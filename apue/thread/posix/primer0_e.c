#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>


#define LEFT    30000000
#define RIGHT   30000200
#define THRNUM	(RIGHT-LEFT+1)

struct thr_arg_st
{
	int n;
};


void *thr_primer(void *p)
{
	int i,j,flag;

	i = ((struct thr_arg_st *)p)->n;

	flag = 1;
	for(j = 2; j <= i/2 ; j++ )
	{
		if(i % j == 0)
		{
			flag = 0;
			break;
		}
	}

	if(flag)
		printf("%d is a primer.\n",i);

	pthread_exit(p);
}



int main()
{
	int i,err;
	pthread_t tid[THRNUM];
	struct thr_arg_st *p;

	for(i = LEFT; i <= RIGHT; i++)
	{
		p = malloc(sizeof(*p));
		/*if error*/
		p->n = i;

		err = pthread_create(tid+(i-LEFT),NULL,thr_primer,p);
		if(err)
		{
			fprintf(stderr,"pthread_create():%s\n",strerror(err));
			exit(1);
		}

	}

	void *retp;
	for(i = LEFT; i <= RIGHT; i++)
	{
		pthread_join(tid[i-LEFT],&retp);
		free(retp);
	}
	exit(0);
}



