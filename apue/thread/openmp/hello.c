#include <stdio.h>

int main()
{
#pragma omp parallel
{
	puts("hello");
	puts("world");
}
	return 0;
}

