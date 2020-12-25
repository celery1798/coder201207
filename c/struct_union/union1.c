#include <stdio.h>
#include <stdlib.h>


union node
{
	unsigned int x;
	struct
	{
		unsigned short low;
		unsigned short high;
	}y;
};

int main()
{
	union node a;

	a.x = 0x11223344;

	printf("%x\n",a.y.low + a.y.high);

	exit(0);
}

