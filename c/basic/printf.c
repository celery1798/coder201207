#include <stdio.h>
#include <stdlib.h>
// format : %[修饰符]输出格式
int main()
{
	int i = 1,j = 2,k = 3,ii = 1234567,num = 0x12;
	float f = 456.789;
	char ch = 'A';
	
	printf("Hello World\n");

	printf("Hello:%d\n",i);
	printf("i = %d, j = %d, k = %d\n",i,j,k);

	printf("ch = %c\n",ch);
	printf("ch = %c\n",ch+i);
	printf("%d\n",ch+k);

	printf("f = %f\n",f);
	printf("f = %e\n",f);
	printf("f = %g\n",f);
	printf("f = %.1f\n",f);

	printf("ii = %10dAAA\n",ii);
	printf("ii = %-10dAAA\n",ii);
	printf("ii = %2d\n",ii);

	printf("f = %10.1f\n",f);

	printf("%15s\n","GoodMorning!");
	printf("%5s\n","GoodMorning!");
	printf("%.5s\n","GoodMorning!");

	exit(0); 	//return 0;
}








