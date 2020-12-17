#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

void test2()
{
	int num,ct_even = 0,ct_odd = 0;
	float sum_even = 0,sum_odd = 0;

	while(scanf("%d",&num) == 1 && num != 0)
	{
		if(num % 2 == 0)
		{
			ct_even ++;
			sum_even += num;
		}
		else
		{
			ct_odd ++;
			sum_odd += num;
		}			
	}
	printf("ODD:%d\tAVE:%f\n",ct_odd,sum_odd/ct_odd);
	printf("EVEN:%d\tAVE:%f\n",ct_even,sum_even/ct_even);

}

void test4()
{
	long int f1 = 1,f2 = 1;
	int i;

	for(i = 1 ; i <= 20 ;i++)
	{
		printf("%10ld%10ld",f1,f2);
		if(i % 2 == 0)
			printf("\n");
		
		f1 += f2;
		f2 += f1;
	}
}

#define LINE	6

void test9()
{
	int i,j;
	char start = 'F',ch;

	for(i = 0 ; i < LINE ; i++)
	{
		// _
		for(j = 0 ; j < i; j++)
			printf("_");


		// ch
		for(ch = start,j = 0; j <= i; j++)
			printf("%c",ch--);
	
		printf("\n");
	}
}

#define MAX	100
#define MIN	0

void test17()
{
	int min = MAX,max = MIN,num;

	printf("Please enter (q for quit) :");
	while(scanf("%d",&num) == 1)
	{
		if(num < MIN || num > MAX)
		{
			printf("Enter error! Please try again\n");
			sleep(1);
			printf("Please enter (q for quit) :");
			continue;
		}

		min = num < min ? num : min;
		max = num > max ? num : max;
		printf("Please enter (q for quit) :");
	}

	printf("MIN = %d\tMAX = %d\n",min,max);
}


int main()
{

//	test1();
//	test6();
//	test14_1();
//	test5();
//	test2();
//	test4();
//	test9();
	test17();

	exit(0); 	//return 0;
}









