//15.10.19
//动态查找：
//BST（二叉排序树）

#include <stdio.h>
#include <stdlib.h>

typedef struct tree 
{
	int data;
	struct tree *LChild,*RChild;
}Tree;

/*void createTree(Tree **t)
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
}*/

void insertBST(Tree **t,int key)
{
	Tree *p;
	p = (Tree *)malloc(sizeof(Tree));
	p->data = key;
	p->LChild = NULL;
	p->RChild = NULL;

	if(*t == NULL)
		*t = p;
	else
	{
		if((*t)->data > p->data)
			insertBST(&(*t)->LChild,key);
		else
			insertBST(&(*t)->RChild,key);
	}		
}

void insertBST_Tree(Tree **t,int key)
{
	Tree *x,*p,*q;
	x = (Tree *)malloc(sizeof(Tree));
	x->data = key;
	x->LChild = NULL;
	x->RChild = NULL;

	if(*t == NULL)
		*t = x;
	else
	{
		p = *t;
		while(p)
		{
			q = p;
			if(x->data < p->data)
				p = p->LChild;
			else
				p = p->RChild;
		}
		if(x->data < q->data)
			q->LChild = x;
		else
			q->RChild = x;
	}
}

Tree * createBST()
{
	int key;
	Tree *t = NULL;

	scanf("%d",&key);
	while(key != 0)
	{
		insertBST_Tree(&t,key);
		scanf("%d",&key);
	}
	return t;
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

void BST_search(Tree *t,int key)
{
	if(t == NULL)
		printf("do not have the data!\n");
	else
	{
		if(key == t->data)
			printf("%d\n",t->data);
		else if(key < t->data)
		{
			t = t->LChild;
			BST_search(t,key);
		}
		else
		{
			t = t->RChild;
			BST_search(t,key);
		}
	}
}

void BST_search_data(Tree *t,int key)
{
	while(t && t->data != key)
	{
		if(t->data > key)
			t = t->LChild;
		else
			t =t->RChild;
	}
	if(t->data == key)
		printf("%d\n",t->data);
	else
		printf("do not have the data!\n");
}

int main()
{
	Tree *t;
	Tree *result;
	t = createBST();
	inorder(t);
	printf("\n");

	BST_search(t,3);
	BST_search_data(t,15);

	return 0;
}
