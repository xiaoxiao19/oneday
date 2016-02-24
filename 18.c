//15.9.29
/*
二叉树的镜像：
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
*/

#include <stdio.h>
#include <stdlib.h>

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
		t =(Tree *)malloc(sizeof(Tree));
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

void image(Tree *t)
{
	Tree *p;

	if(t)
	{
		p = t->LChild;
		t->LChild = t->RChild;
		t->RChild = p;
	
		image(t->LChild);
		image(t->RChild);
	}

}

void inOrder(Tree *t)
{
	if(t)
	{
		inOrder(t->LChild);
		printf("%d   ",t->data);
		inOrder(t->RChild);	
	}
}


int main()
{
	Tree *t;

	t = createTree();
	preOrder(t);	
	printf("\n");

	image(t);
	preOrder(t);
	printf("\n");
	inOrder(t);
	printf("\n");

	return 0;
}



