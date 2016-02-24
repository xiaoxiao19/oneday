//15.10.12
//实现先序搜索树，并实现树的遍历

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100

typedef enum{Link,Thread}PointerTag;

typedef struct tree
{
	int data;
	struct tree *LChild,*RChild;
	PointerTag ltag;
	PointerTag rtag;
}Tree;

Tree *pre;

void createTree(Tree **t)
{
	int m = 0;

	scanf("%d",&m);

	if(m == 0)
		(*t) = NULL;
	else
	{
		(*t) = (Tree *)malloc(sizeof(Tree));
		(*t)->data = m;
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

void preorder_thread(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};
	Tree *last = NULL,*p;
	int top = 0;
	
	if(t != NULL)
	{
		stack[++top] = t;
		while(top > 0)
		{
			p = stack[top];
			top--;
			if(p->LChild)
				p->ltag = 0;
			else
			{
				p->ltag = 1;
				p->LChild = NULL;//将没有左子树的结点的左子树设置执行NULL
			}
			if(last) //last指针用于指向当前访问元素的前一个元素
			{
				if(last->RChild)
					last->rtag = 0;
				else
				{
					last->rtag = 1;
					last->RChild = p;//
				}
			}
			
			last = p;
			if(p->RChild)
				stack[++top] = p->RChild;
			if(p->LChild)
				stack[++top] = p->LChild;
		}
		last->rtag = 1;
	}
}


void preordertree_thread(Tree *t)
{
	while(t)
	{
		printf("%d   ",t->data);
		if(t->ltag == 0)
			t = t->LChild;
		else
			t = t->RChild;
	}
}

int main()
{
	Tree *t;

	createTree(&t);
	preOrder(t);
	printf("\n");

	preorder_thread(t);
	preordertree_thread(t);
	printf("\n");

	return 0;
}
