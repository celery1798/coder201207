#include <stdio.h>
#include <stdlib.h>

void test1()
{
	int f[10] = {1,1};
	int i,j,t;

	for(i = 2;i < 10; i++)
		f[i] = f[i-1] + f[i-2];
	
	for(i = 0; i < 10; i++)
		printf("%d ",f[i]);
	printf("\n");

	for(i = 9; i >= 0; i--)
		printf("%d ",f[i]);
	printf("\n");

	i = 0;
	j = 10-1;

	while(i < j)
	{
		t = f[i];
		f[i] = f[j];
		f[j] = t;
		i++;
		j--;
	}
	for(i = 0; i < 10; i++)
		printf("%d ",f[i]);
	printf("\n");
}

void test4()
{

	int a[32],i,num,base;
	
	printf("Please enter for NUM:");
	scanf("%d",&num);
	printf("Please enter for BASE:");
	scanf("%d",&base);
	
	i = 0;

	do
	{
		a[i] = num % base;	
		i++;
		num = num/base;
	}while(num != 0);

	for(i--; i >= 0; i--)
	{
		if(a[i] >= 10)
			printf("%c ",a[i]-10+'A');
		else
			printf("%d ",a[i]);
	}
	printf("\n");

}

int main()
{
//	test1();
	test4();

	exit(0); 	//return 0;
}








