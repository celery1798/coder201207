


void f1(void *p)
{
	printf("f1():%s\n");
}
void f2(void *p)
{
	printf("f2():%s\n");
}

int main()
{
	int job1;

	job1 = at_addjob(5,f1,"aaa");
	if(job1 <= 0)
	{
		strerror(-job1);
		exit(1);
	}

	job2 = at_addjob_repeat(2,f2,"bbb");

	job3 = at_addjob(7,f1,"ccc");


	
	while(1)
	{
		write(1,".",1);
		sleep(1);
	}
	//..bbb...aaa..ccc..............
	exit(0);
}




