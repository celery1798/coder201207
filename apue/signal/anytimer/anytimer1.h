#ifndef ANYTIMER_H__
#define ANYTIMER_H__


#define JOBMAX	1024

typedef void at_jobfunc_t(void *);

int at_addjob(int sec,at_jobfunc_t *jobp, void *arg);
/*
return:	>= 0		成功，返回任务ID
		== -EINVAL	失败，参数非法 
		== -ENOSPC	失败，任务数组满

*/


int at_canceljob(int id);
/*
return:	== 0		成功，指定任务已取消 
		== -EINVAL  失败，参数非法
		== -EBUSY	失败，指定任务早已结束 
		== -ECANCELED	失败，指定任务已被取消 
*/

int at_waitjob(int id);
/*
return: == 0        成功，指定任务已收尸并释放资源 
		== -EINVAL  失败，参数非法
*/

#endif




