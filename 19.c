//15.9.29
/*
从上往下打印二叉树（二叉树的层次遍历）
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

Tree *createTree()
{
	Tree *t;
	int ele = 0;
	
	scanf("%d",&ele);
	if(ele == 0)
		t = NULL;
	else
	{
		t = (Tree *)malloc(sizeof(Tree));
		t->data = ele;
		t->LChild = createTree();
		t->RChild = createTree();
	}
	return t;
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

void levelOrder(Tree *t)
{
	Tree *queue[MAX_NODE] = {NULL};
	int front = 0,rear = 0;

	if(t)
	{
		queue[++rear] = t;
		while(front<rear)
		{
			t = queue[++front];
			printf("%d   ",t->data);
			if(t->LChild)
				queue[++rear] = t->LChild;
			if(t->RChild)
				queue[++rear] = t->RChild;
		}		
	}
}

int main()
{
	Tree *t;
	
	t = createTree();
	preOrder(t);	
	printf("\n");

	levelOrder(t);
	printf("\n");

	return 0;
}
