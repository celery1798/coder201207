#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define		QUART	950
#define 	WEIGHT	3.0e-23

void test1()
{
	float q,total;
	
	printf("Please enter : ");	
	scanf("%f",&q);
	
	total = q * QUART / WEIGHT;

	printf("TOTAL: %e\n",total);

}

void test2()
{

	float a,b,c,s,area;

	printf("Please enter : ");
	scanf("%f%f%f",&a,&b,&c);
	
	// if error
	if(a+b<=c || b+c<=a || a+c<=b)
		return ;
	
	s = 1.0/2*(a+b+c);

	area = sqrt(s * (s-a) * (s-b) * (s-c));	

	printf("area = %f\n",area);
}

void test3()
{
	float a,b,c,dis,p,q,x1,x2;

	printf("Please enter : ");
	scanf("%f%f%f",&a,&b,&c);

	dis = b*b - 4*a*c;
	p = -b/(2*a);
	q = sqrt(dis)/(2*a);

	x1 = p + q;
	x2 = p - q;
	
	printf("x1 = %f, x2 = %f\n",x1,x2);

}

int main()
{
//	test1();
	test2();
//	test3();

	exit(0); 	//return 0;
}




