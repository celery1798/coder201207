#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE    32

struct score
{
	int id;
	char name[NAMESIZE];
	int math;
};

typedef struct node_st
{
	struct score data;
	struct node_st *l,*r;
}TREE;

TREE *tree = NULL;

void print_s(void *data)
{
	struct score *d = data;
	printf("%d %s %d\n",d->id,d->name,d->math);
}

int insert(TREE **root,struct score *data)
{
	struct node_st *node;

	if(*root == NULL)
	{
		node = malloc(sizeof(*node));
		if(node == NULL)
			return -1;
		node->data = *data;
		node->l = node->r = NULL;
		*root = node;
		return 0;
	}

	if(data->id <= (*root)->data.id)
		return insert(&(*root)->l,data);
	return insert(&(*root)->r,data);
}

static void draw_(TREE *root,int level)
{
	int i;
	if(root == NULL)
		return ;
	draw_(root->r,level+1);
	for(i = 0 ; i < level; i++)
		printf("    ");
	print_s(&root->data);
	draw_(root->l,level+1);
}

void draw(TREE *root)
{
	draw_(root,0);
	printf("\n\n");
//	getchar();
}

static int get_num(TREE *root)
{
	if(root == NULL)
		return 0;
	return get_num(root->l) + 1 + get_num(root->r);	
}

static struct node_st *find_min(TREE *root)
{
	if(root->l == NULL)
		return root;
	return find_min(root->l);
}

static void turn_left(TREE **root)
{
	struct node_st *cur = *root;

	*root = cur->r;
	cur->r = NULL;

	find_min(*root)->l = cur;
//	draw(tree);
}


static struct node_st *find_max(TREE *root)
{
	if(root->r == NULL)
		return root;
	return find_max(root->r);
}  

static void turn_right(TREE **root)
{   
	struct node_st *cur = *root;

	*root = cur->l;
	cur->l = NULL;

	find_max(*root)->r = cur;
//	draw(tree);
}

void balance(TREE **root)
{
	int sub;
	if(*root == NULL)
		return ;

	while(1)
	{
		sub = get_num((*root)->l) - get_num((*root)->r);
		if(sub >= -1 && sub <= 1)
			break;
		if(sub < -1)
			turn_left(root);
		else
			turn_right(root);
	}

	balance(&(*root)->l);
	balance(&(*root)->r);

}


int main()
{
	struct score tmp;
	int arr[] = {1,2,3,7,6,5,9,8,4};
	int i;

	for(i = 0 ;i < sizeof(arr)/sizeof(*arr); i++)
	{
		tmp.id = arr[i];
		snprintf(tmp.name,NAMESIZE,"Stu%d",arr[i]);
		tmp.math = 100-arr[i];

		insert(&tree,&tmp);
	}
	
	draw(tree);

	balance(&tree);
	draw(tree);

	travel(tree);


	exit(0);
}











