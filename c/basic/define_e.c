#include <stdio.h>

#define PI   3.14
#define M	 (3+3)

//#define MAX(a,b)	((a) > (b) ? (a) : (b))
//#define MAX(a,b)	({int A=a,B=b; ((A) > (B) ? (A) : (B));})
#define MAX(a,b)	({typeof(a) A=a,B=b; ((A) > (B) ? (A) : (B));})

int main()
{
	int i = 3,j = 5;

	printf("i = %d, j = %d\n",i,j);

	printf("%d\n",MAX(i++,j++));

	printf("i = %d, j = %d\n",i,j);
	return 0;
}


