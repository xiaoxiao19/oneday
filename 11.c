//15.9.20
/*
统计有环单链表的环中结点个数
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct pLNode
{
	int data;
	struct pLNode *next;
}pLNode;

void init(pLNode **l)
{
	(*l) = (pLNode *)malloc(sizeof(pLNode));
	(*l)->next = NULL;
}

void insert(pLNode *l)
{
	int ele = 0;
	pLNode *p;

	while(1)
	{
		scanf("%d",&ele);
		if(ele == 0)  break;
		p = (pLNode *)malloc(sizeof(pLNode));
		p->data = ele;
		p->next = l->next;
		l->next = p;
		p = l;
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
		pEnd = pEnd->next;

	if(l->next && l->next->next)
		pEnd->next = l->next->next;
}

int count(pLNode *l)
{
	int num = 1;
	pLNode *p,*q;
	l = l->next;
	p = l;
	q = l;
	
	while(q->next && q->next->next)
	{
		q = q->next->next;
		p = p->next;

		if(p == q)
		{
			printf("%d\n",p->data);
			p = p->next;
			while(p != q)
			{
				p = p->next;
				num++;
			}
			break;
		}
	}

	return num;
}

int main()
{
	pLNode *L;
	int res;	

	init(&L);
	insert(L);
	print(L);
	//createCycle(L);

	res = count(L);
	if(res != 1)
		printf("result is:%d\n",res);
	else
		printf("have no cycle!\n");

	return 0;
}
