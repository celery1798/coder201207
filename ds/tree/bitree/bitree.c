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
}

int main()
{
	struct score tmp;
	TREE *tree = NULL;
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

	exit(0);
}











