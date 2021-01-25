#include <stdio.h>
#include <omp.h>

int main()
{
#pragma omp parallel sections
{
#pragma omp section
	printf("[%d]hello\n",omp_get_thread_num());

#pragma omp section
	printf("[%d]world\n",omp_get_thread_num());
}
	return 0;
}

