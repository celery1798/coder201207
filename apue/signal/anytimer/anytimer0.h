#ifndef ANYTIMER_H__
#define ANYTIMER_H__


#define JOBMAX	1024

typedef void at_jobfunc_t(void *);

int addjob(int sec,at_jobfunc_t *jobp, void *arg);
/*
return:	>= 0		成功，返回任务ID
		== -EINVAL	失败，参数非法 
		== -ENOSPC	失败，任务数组满

*/



#endif




