#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define THRNUM	4	

static int num = 0;
static pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

int next(int t)
{
	if(t+1 == THRNUM)
		return 0;
	return t+1;
}

void *thr_func(void *p)
{
	int n =(int)p;
	int ch = 'a' + n;

	while(1)
	{
		pthread_mutex_lock(&mut);
		while(num != n)
			pthread_cond_wait(&cond,&mut);
		write(1,&ch,1);
		num = next(num);
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mut);
	}
	pthread_exit(NULL);
}
	
int main()
{
	int i,err;
	pthread_t tid[THRNUM];

	for(i = 0; i < THRNUM; i++)
	{
		err = pthread_create(tid+i,NULL,thr_func,(void *)i);
		if(err)
		{
			fprintf(stderr,"pthread_create():%s\n",strerror(err));
			exit(1);
		}
	}

	alarm(5);

	for(i = 0; i < THRNUM; i++)
		pthread_join(tid[i],NULL);

	//mutex destroy
	//COND DESTROY

	exit(0);
}








