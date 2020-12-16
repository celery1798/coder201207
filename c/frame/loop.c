#include <stdio.h>
#include <stdlib.h>

/*
	for(exp1初始化  ;   exp2循环成立条件   ;  exp3变化条件)
	{
		statements;
	}

	while(expr)
	{
		statements;
	}

	do
	{
		statements;
	}while(expr);



*/



int main()
{
	int sum = 0;
	int i = 1;

loop:
	sum += i;	
	i++;
	if(i <= 100)
		goto loop;




/*	
	do
	{
		sum += i;
		i++;
	}while(i <= 100);
*/

/*
	while(i <= 100)
	{
		sum += i;
		i++;
	}
*/
/*
//for(i = 1 ; i <= 100; i++)

	for( ; ; )
	{
		sum += i;
		i++;
		if(i > 100)
			break;
	}
*/	

	printf("sum = %d\n",sum);
	
	exit(0); 	//return 0;
}

