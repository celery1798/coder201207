#ifndef _RELAYER_H__
#define _RELAYER_H__


#define REL_JOBMAX		10000

enum
{
	STATE_RUNNING=1,
	STATE_CANCELED,
	STATE_OVER
};

struct rel_stat_st
{
	int fd1,fd2;
	int state;
};


int rel_addjob(int fd1,int fd2);
/*return	>= 0		成功，返回任务ID
			==-EINVAL	失败，参数非法
			==-ENOSPC	失败，任务数组满
			==-ENOMEM	失败，内存分配失败
*/

int rel_canceljob(int id);
/*
return		== 0		成功，指定任务已取消 
			==-EINVAL   失败，参数非法
			==-ECANCELED	失败，指定任务早已取消 
*/

int rel_statjob(int id,struct rel_stat_st *);
/*
return 		== 0        成功，指定任务状态回填
			==-EINVAL   失败，参数非法
*/


int rel_waitjob(int id,struct rel_stat_st *);
/*
return		== 0        成功，指定任务已释放资源 
			==-EINVAL   失败，参数非法
*/


#endif


