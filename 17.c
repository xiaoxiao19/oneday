//15.9.26
/*
二叉树的镜像：请完成一个函数，输入一个二叉树，该函数输出它的镜像。
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

Tree * preOrderCreateTree()
{
	Tree *t = NULL;
	int ele = 0;

	scanf("%d",&ele);	
	if(ele == 0)
		t = NULL;
	else
	{
		t = (Tree *)malloc(sizeof(Tree));
		t->data = ele;
		t->LChild = preOrderCreateTree();
		t->RChild = preOrderCreateTree();
	}
	return t;
}

void preOrderTravel(Tree *t)
{
	if(t)
	{
		printf("%d  ",t->data);
		preOrderTravel(t->LChild);
		preOrderTravel(t->RChild);
	}		
}

void preOrder(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};//
	Tree *p = NULL;
	int top = 0;

	if(t == NULL)
		printf("The tree is null!\n");
	else
	{
		do
		{
			printf("%d  ",t->data);
			p = t->RChild;
			if(p != NULL)
				stack[++top] = p;
			t = t->LChild;			
			if(t == NULL)
			{
				t = stack[top];
				top--;
			}
		}
		while(t != NULL);
	}
}

void inOrderTravel(Tree *t)
{
	if(t)
	{
		inOrderTravel(t->LChild);
		printf("%d  ",t->data);
		inOrderTravel(t->RChild);
	}
}

void inOrder(Tree *t)
{
	Tree *stack[MAX_NODE] = {NULL};
	Tree *p = NULL;
	int top = 0,i = 1;

	if(t == NULL)
		printf("the tree is NULL\n");
	else
	{
		do	
		{
			while(t)
			{
				stack[++top] = t;
				t = t->LChild;
			}
			if(top == 0)
				i = 0;
			else
			{
				t = stack[top];
				top--;
				printf("%d  ",t->data);
				t = t->RChild;
			}
		}
		while(i);
	}
}

void postOrderTravel(Tree *t)
{
	if(t)
	{
		postOrderTravel(t->LChild);
		postOrderTravel(t->RChild);
		printf("%d  ",t->data);
	}
}

void postOrder(Tree *t)
{
	Tree *stack1[MAX_NODE] = {NULL};
	int top = 0;
	int i = 1;
	int stack2[MAX_NODE] = {0};

	if(t == NULL)
		printf("the tree is null!\n");
	else
	{
		do
		{
			while(t)
			{
				stack1[++top] = t;
				stack2[top] = 0;
				t = t->LChild;
			}
			if(top == 0)
				i = 0;
			else if(stack2[top] == 0)
			{
				t = stack1[top]->RChild;
				stack2[top] = 1;
			}
			else
			{
				t = stack1[top];
				top--;
				printf("%d  ",t->data);
				t = NULL;
			}
		}
		while(i != 0);
	}
}

int main()
{
	Tree *tree;

	tree = preOrderCreateTree();
	preOrderTravel(tree);
	printf("\n");

	preOrder(tree);
	printf("\n");

	inOrderTravel(tree);
	printf("\n");
	
	inOrder(tree);
	printf("\n");

	postOrderTravel(tree);
	printf("\n");

	postOrder(tree);
	printf("\n");

	return 0;
}
