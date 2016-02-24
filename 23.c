//15.10.13
//实现中序搜索树，并遍历树

#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE 100

typedef struct tree
{
	int data;
	struct tree *LChild,*RChild;
	int ltag,rtag;
}Tree;

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

void inorder(Tree *t)
{
	if(t)
	{
		inorder(t->LChild);
		printf("%d   ",t->data);
		inorder(t->RChild);
	}
}

void inorder_thread(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};
	Tree *last = NULL,*p=t;
	int top = 0;

	while(p || top > 0)
	{
		if(p)
		{
			stack[++top] = p;
			p->ltag = 0;
			p = p->LChild;
		}
		else
		{
			p = stack[top--];
			if(p->LChild)
				p->ltag = 0;
			else
			{
				p->ltag = 1;
				p->LChild = NULL;
			}
			if(last)
			{
				if(last->RChild)
					last->rtag = 0;
				else
				{
					last->rtag = 1;
					last->RChild = p;
				}
			}
			last = p;
			p = p->RChild;
			last->rtag = 1;
		}
	}
}

void inordertree_thread(Tree *t)
{
	if(t)
	{
		while(t->ltag == 0)//
			t = t->LChild;
		while(t)
		{
			printf("%d   ",t->data);	
			if(t->rtag == 1)
				t = t->RChild;
			else
			{
				t = t->RChild;
				while(t->ltag == 0)//
					t =t->LChild;
			}
		}
	}
}

int main()
{
	Tree *t;
	createTree(&t);
	inorder(t);
	printf("\n");

	inorder_thread(t);
	inordertree_thread(t);
	printf("\n");

	return 0;
}

