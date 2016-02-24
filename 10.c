//15.9.20
/*
判断有环单链表的环入口
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
	int ele = 0;

	while(1)
	{
		scanf("%d",&ele);
		if(ele == 0)  break;
		l->next = (pLNode *)malloc(sizeof(pLNode));
		l = l->next;
		l->data = ele;
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

void createCycle(pLNode *l)
{
	pLNode *pEnd;
	l = l->next;
	pEnd = l;

	while(pEnd->next)
	{
		pEnd = pEnd->next;
	}

	if(l->next && l->next->next)
		pEnd->next = l->next->next;
}

pLNode * find(pLNode *l)
{
	pLNode *p,*q;
	l = l->next;
	p = l;
	q = l;

	while(p->next && p->next->next)
	{
		p = p->next->next;
		q = q->next;

		if(p == q)
		{
			while(p != l)
			{
				p = p->next;
				l = l->next;
			}
			return p;
		}
	}	
	
	return NULL;
}

int main()
{
	pLNode *L;
	pLNode *res;

	init(&L);
	insert(L);
	print(L);
	createCycle(L);

	res = find(L);
	if(res != NULL)
	{
		printf("%d\n",res->data);
	}

	return 0;
}
