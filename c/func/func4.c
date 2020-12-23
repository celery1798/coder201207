#include <stdio.h>
#include <stdlib.h>

void d()
{
	printf("[%s:%d]Begin!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]End!\n",__FUNCTION__,__LINE__);
}

void c()
{
	printf("[%s:%d]Begin!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]Call d()!\n",__FUNCTION__,__LINE__);
	d();
	printf("[%s:%d]d() returned!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]End!\n",__FUNCTION__,__LINE__);
}

void b()
{
	printf("[%s:%d]Begin!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]Call c()!\n",__FUNCTION__,__LINE__);
	c();
	printf("[%s:%d]c() returned!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]End!\n",__FUNCTION__,__LINE__);
}

void a()
{
	printf("[%s:%d]Begin!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]Call b()!\n",__FUNCTION__,__LINE__);
	b();
	printf("[%s:%d]b() returned!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]End!\n",__FUNCTION__,__LINE__);
}


int main()
{
	printf("[%s:%d]Begin!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]Call a()!\n",__FUNCTION__,__LINE__);
	a();
	printf("[%s:%d]a() returned!\n",__FUNCTION__,__LINE__);
	printf("[%s:%d]End!\n",__FUNCTION__,__LINE__);

	exit(0);
}

