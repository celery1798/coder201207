#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>


void f1(void)
{
	puts("f1 () is working.");
}

void f2(void)
{
	puts("f2 () is working.");
}
void f3(void)
{
	puts("f3 () is working.");
}

int main(int argc,char *argv[])
{

	puts("Begin!");

	atexit(f1);
	atexit(f2);
	atexit(f3);

	puts("End!");

	exit(0);
}



