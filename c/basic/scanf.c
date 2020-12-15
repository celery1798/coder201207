#include <stdio.h>
//scanf(const char *format,地址表)
//%[修饰符]格式字符
int main()
{
	int i,j,k;
	char ch;
	float f;

	printf("Please enter for int:");
	scanf("%d%d%d",&i,&j,&k);
	printf("i = %d, j = %d, k = %d\n",i,j,k);

	getchar();

	printf("Please enter for char :");
	scanf("%c",&ch);
	printf("ch = %d\n",ch);


	printf("Please enter for float :");
	scanf("%f",&f);
	printf("f = %f\n",f);
	
	return 0;
}

