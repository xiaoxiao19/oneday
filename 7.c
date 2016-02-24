//15.9.18
/*
输入两个递增排序的链表，合并这两个链表并使新链表的结点仍然是按照递增排序的
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
	pLNode *p;
	int ele;

	while(1)
	{
		scanf("%d",&ele);
		if(ele == 0)  break;
		p = (pLNode *)malloc(sizeof(pLNode));
		p->data = ele;
		p->next = l->next;
		l->next = p;
		l = p;
	}
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

pLNode *combine(pLNode *p,pLNode *q)
{
	pLNode *pcurHead,*pcurNew;
	p = p->next;
	q = q->next;
	pcurHead = NULL;
	pcurNew = NULL;
	
	if(p->data > q->data)
	{
		pcurHead = q;
		q = q->next;
	}
	else
	{
		pcurHead = p;
		p = p->next;
	}

	pcurNew = pcurHead;	

	while(p && q)
	{
		if(p->data > q->data)
		{
			pcurNew->next = q;
			pcurNew = pcurNew->next;
			q = q->next;
		}
		else
		{
			pcurNew->next = p;
			pcurNew = pcurNew->next;
			p = p->next;
		}
	}

	if(p)
		pcurNew->next = p;	

	if(q)
		pcurNew->next = q;

	return pcurHead;
}

int main()
{
	pLNode *p,*q,*res;
	
	init(&p);
	init(&q);

	insert(p);
	print(p);

	insert(q);
	print(q);

	res = combine(p,q);

	print(res);

	return 0;
}
