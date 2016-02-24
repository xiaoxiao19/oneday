//15.9.19
/*
求链表的中间结点：
求链表的中间结点，如果链表中结点总数为奇数，返回中间结点；如果结点总数是偶数，返回中间结点的任意一个;
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode 
{
	int data;
	struct LNode *next;
}pLNode;

void init(pLNode **l)
{
	(*l) = (pLNode *)malloc(sizeof(pLNode));
	(*l)->next = NULL;
}

void insert(pLNode *l)
{
	int ele;
	
	while(1)
	{
		scanf("%d",&ele);
		if(ele == 0) break;
		l->next = (pLNode *)malloc(sizeof(pLNode));
		l = l->next;
		l->data = ele;
	}
}

pLNode * mid(pLNode *l)
{
	pLNode *p,*q;
	p = l->next;
	q = l->next;

	while(q->next && q->next->next)//这里不仅两个判定条件都要有，并且要注意判断的前后顺序，否则会出现段错误
	{
		q = q->next->next;
		p = p->next;
	}
		
	return p;
}

void print(pLNode *l)
{
	l = l->next;
	while(l)
	{
		printf("%d  ",l->data);
		l = l->next;
	}
	printf("\n");
}

int main()
{
	pLNode *L;
	pLNode *res;
	
	init(&L);
	insert(L);
	print(L);

	res = mid(L);
	printf("%d\n",res->data);

	return 0;
}
