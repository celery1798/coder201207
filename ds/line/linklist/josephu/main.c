


typedef struct node
{
	int data;
	struct node *next;
}JOSEPHU;

int main()
{
	int num = 8;
	int count = 3;
	JOSEPHU *ptr;

	ptr = jose_create(num);
	/*if error*/

	jose_show(ptr);

	jose_kill(ptr,count);  //&ptr	//3615284
//	jose_show();			//7
}













