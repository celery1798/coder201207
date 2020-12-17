#include <stdio.h>
#include <stdlib.h>

// auto register static extern

extern int i;
void func()
{
	int a = 1;
	static int b = 1;
	b++;
	a++;
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	printf("%s[%d]:i = %d\n",__FUNCTION__,__LINE__,i);

}

int i = 12;

int main()
{
	int ii = 1;
	auto int i = 1;
	static double d;
	register char ch;



	printf("%s[%d]:i = %d\n",__FUNCTION__,__LINE__,i);



	func();


/*
	func();
	func();
	func();

*/
	
	exit(0); 	//return 0;
}

