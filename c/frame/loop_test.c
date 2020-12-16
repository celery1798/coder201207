#include <stdio.h>
#include <stdlib.h>

#define RATE_SIMP	0.1
#define RATE_COMP	0.05
#define INIT		100

void test1()
{
	double d1 = INIT,d2 = INIT;
	int year = 0;

	while(d1 >= d2)
	{
		d1 += INIT * RATE_SIMP;
		d2 += d2 * RATE_COMP;
		year++;
	}

	printf("d1 = %lf, d2 = %lf\n",d1,d2);
	printf("year = %d\n",year);

}

void test6()
{
	int x,y,z;

	for(x = 0 ; x < 20 ; x++)
	{
		for(y = 0 ; y < 33; y++)
		{
			z = 100 - x - y;
			if(z%3 == 0 && 5*x + 3*y + z/3 == 100)
				printf("%d %d %d\n",x,y,z);
		
		}
	
	}


}

#define LEFT	30000000
#define RIGHT	30000200

void test14_1()
{
	int i,flag = 1,j;

	for(i = LEFT; i <= RIGHT; i++)
	{
		flag = 1;
		for(j = 2; j <= i/2 ; j++ )
		{
			if(i % j == 0)
			{
				flag = 0;
				break;
			}	
		}

		if(flag)
			printf("%d is a primer.\n",i);
	}

}

//	printf((j == i) ? "%d\n" : "%d ",i*j);
void test5()
{
	int i,j;

	for(i = 1; i <= 9; i++)
	{
		for(j = 1; j <= i; j++)
			printf("%d*%d=%-3d",i,j,i*j);
		printf("\n");	
	
	}



}

int main()
{

//	test1();
//	test6();
//	test14_1();
	test5();

	exit(0); 	//return 0;
}









