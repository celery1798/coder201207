#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#include "mytbf.h"

typedef void (*sighandler_t)(int);

struct mytbf_st
{
	int cps;
	int burst;
	int token;
	int pos;
};

static struct mytbf_st *job[MYTBF_MAX];
static int inited = 1;
static sighandler_t alrm_handler_save;

static void alrm_handler(int s)
{
	int i;
	alarm(1);

	for(i = 0 ; i < MYTBF_MAX; i++)
	{
		if(job[i] != NULL)
		{
			job[i]->token += job[i]->cps;
			if(job[i]->token > job[i]->burst)
				job[i]->token = job[i]->burst;
		}
	}
}

static void module_unload()
{
	int i;

	alarm(0);
	signal(SIGALRM,alrm_handler_save);

	for(i = 0 ; i < MYTBF_MAX; i++)
		free(job[i]);
}

static void module_load()
{
	alrm_handler_save = signal(SIGALRM,alrm_handler);
	alarm(1);
	atexit(module_unload);
}

static int get_free_pos()
{
	int i;
	for(i = 0 ; i < MYTBF_MAX; i++)
		if(job[i] == NULL)
			return i;
	return -1;
}

mytbf_t* mytbf_init(int cps,int burst)
{
	struct mytbf_st *me;
	int pos;

	if(inited)
	{
		module_load();
		inited = 0;
	}

	pos = get_free_pos();
	if(pos < 0)
	{
		return NULL;
	}

	me = malloc(sizeof(*me));
	if(me == NULL)
		return NULL;

	me->cps = cps;
	me->burst = burst;
	me->token = 0;

	job[pos]= me;
	me->pos = pos;

	return me;
}

static int min(int a,int b)
{
	if(a < b)
		return a;
	return b;
}

int mytbf_fetchtoken(mytbf_t *tbf, int n)
{
	struct mytbf_st *me = tbf;
	int t;

	if(n <= 0)
		return -EINVAL;

	while(me->token <= 0)
		pause();
	
	t = min(me->token,n);
	me->token -= t;
	return t;
}

int mytbf_returntoken(mytbf_t *tbf,int n)
{
	struct mytbf_st *me = tbf;

	if(n <= 0)
	    return -EINVAL;
		
	me->token += n;
	if(me->token > me->burst)
		me->token = me->burst;
	return 0;
}

void mytbf_destroy(mytbf_t *tbf)
{
	struct mytbf_st *me = tbf;
	job[me->pos] = NULL;
	free(tbf);
}


