#include <stdio.h>
#include <stdlib.h>

/*
if(exp)
{
	state;
}

if-else

if(exp)
{
	state1;
}
else
{
	state2;
}

*/

int main()
{
/*
	int a = 10,b = 9;

	//if(++b < a || a++ > 20 || b--)
	if(b++ <= a && a++ > 20 && b--)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
*/

//if - else 匹配问题：else只与离它最近的if相匹配

	int a = 1,b = 1,c = 2;

	if(a == b)
	{
		if(b == c)
			printf("a == b == c\n");
	}
	else
		printf("a != b\n");



	exit(0); 	//return 0;
}










