

typedef struct node
{
	int conf;
	int exp;
	struct node *next;
}POLY;


int main()
{
	POLY *p1,*p2;
	int a[][2] = {{5,0},{2,1},{8,8},{-3,16}};
	int b[][2] = {{6,1},{12,6},{-8,8}};

	p1 = poly_create(a,4,2);
	p2 = poly_create(b,3,2);

	poly_show(p1);
	poly_show(p2);

	poly_add(p1,p2);
	poly_show(p1);

}




