
#include <stdio.h>

//#include "../include/proto.h"

#include <proto.h>


int main()
{
	struct mlib_chn_st *listptr;
	int listsize;

	/*daemon*/


	/*socket*/

	/*获取频道列表(从medialib模块)*/
	if(mlib_getchnlist(&listptr,&listsize) < 0)
	{
		syslog();	
		
	}
		

	/*创建 thr_list*/
	thr_list_create(listptr,listsize);
	/*if error*/

	

	/*创建 thr_channel    1:1 */
	
	for(i = 0 ; i < listsize; i++)
	{	
		thr_channel_create(   )
		/*if error*/
	}


	while(1)
		pause();

	exit(0);
}






