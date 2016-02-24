//15.9.29
/*
求二叉树的深度
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100

typedef struct tree
{
	int data;
	struct tree *LChild;
	struct tree *RChild;
}Tree;

void createTree(Tree **t)
{
	int ele = 0;
	
	scanf("%d",&ele);
	if(ele == 0)
		(*t) = NULL;
	else
	{
		(*t) = (Tree *)malloc(sizeof(Tree));
		(*t)->data = ele;
		createTree(&((*t)->LChild));
		createTree(&((*t)->RChild));
	}
}

void preOrder(Tree *t)
{
	if(t)
	{
		printf("%d   ",t->data);
		preOrder(t->LChild);
		preOrder(t->RChild);
	}
}

int search_depth(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};
	int front = 0,rear=0,level=0,depth=0;

	if(t)
	{
		stack[++rear] = t;
		level = rear;
		while(front < rear)
		{
			t = stack[++front];
			printf("%d   ",t->data);
			if(t->LChild)
				stack[++rear] = t->LChild;
			if(t->RChild)
				stack[++rear] = t->RChild;
			if(front == level)
			{
				depth++;
				level = rear;
			}
		}
	}
	printf("\nthe depth is :%d\n",depth);
}

int max(int i,int j)
{
	if(i>j)
		return i;
	else
		return j;
}

int depth(Tree *t)
{
	int nLeftDepth;
	int nRightDepth;
	if(t)
		return 0;	

	nLeftDepth = depth(t->LChild);
	nRightDepth = depth(t->RChild);
	return max(nLeftDepth,nRightDepth)+1;
}

void print_leves(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};
	int top = 0;
	int num = 0;	

	if(t != NULL)
	{
		stack[++top] = t;
		while(top)
		{
			t = stack[top--];
			if(t->LChild == NULL && t->RChild == NULL)
			{
				printf("%d   ",t->data);
				num++;
			}
			if(t->RChild)
				stack[++top] = t->RChild;
			if(t->LChild)
				stack[++top] = t->LChild;
		}	
	}
	printf("\nthe leves are:%d\n",num);
}


int main()
{
	Tree *t;

	createTree(&t);
	preOrder(t);
	printf("\n");

	search_depth(t);

	print_leves(t);
	printf("\n");

	return 0;
}
