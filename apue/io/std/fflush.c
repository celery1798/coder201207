#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


/*
缓冲区作用：大多数情况下，缓冲区的存在是件好事，作用合并系统调用 

行缓冲：换行刷新，满了刷新，强制刷新
全缓冲：（默认，只要不是涉及到终端设备）满了刷新，强制刷新
无缓冲：立即输出，如stderr

*/


int main()
{

	int i;

	for(i = 0 ; i < 5; i++)
	{
		putchar('x');
		fflush(NULL);
		sleep(1);		
	}

	putchar('\n');
	







/*
	int i = 1,j = 3,k = 0;

	printf("befor while");
	fflush(NULL);

	while(i < j);
	{
		k++;
		i++;
	}

	printf("after while");
	fflush(stdout);

	printf("k = %d\n",k);
*/	
	exit(0);
}











