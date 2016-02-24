//15.9.20
/*
判断一个单向链表是否形成环
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
	*l = (pLNode *)malloc(sizeof(pLNode));
	(*l)->next = NULL;
}

void insert(pLNode *l)
{
	int ele;
	pLNode *p = NULL;

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

void createCycle(pLNode *l)
{
	pLNode *pEndNode;
	l = l->next;
	pEndNode = l;	

	while(pEndNode->next)//最后一个结点的判定条件
		pEndNode = pEndNode->next;

	printf("%d  ",pEndNode->data);

	if(l->next && l->next->next)
		pEndNode->next = l->next->next;
	printf("%d\n",l->next->next->data);
		
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

int isCycle(pLNode *l)
{
	pLNode *p;
	l = l->next;
	p = l;

	while(l->next && l->next->next)
	{
		l = l->next->next;
		p = p->next;

		if(p == l)
			return 1;
	}
	return 0;
}

int main()
{
	pLNode *L;
	int res;

	init(&L);
	insert(L);
	print(L);
	//createCycle(L);

	res = isCycle(L);
	if(res == 1)
		printf("have cycle!\n");
	else
		printf("not have cycle\n");

	return 0;
}
