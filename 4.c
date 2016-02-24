//15.9.17
/*
给定单项链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点，链表结点与函数定义如下：
struct ListNode	
{
	int m_nValue;
	ListNode *m_pNext;
};

void DeleteNode(ListNode **pListHead,ListNode *pToBeDeleted);
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
	int data;
	struct ListNode *next;
}pListNode;

void init(pListNode **L)
{
	(*L) = (pListNode *)malloc(sizeof(pListNode));
	(*L)->next = NULL;
}

void deleteNode(pListNode **L,pListNode *pDel)
{
	pListNode *p,*q;
	if(pDel->next)
	{
		p = pDel->next;
		q = p->next;
		pDel->data = p->data;
		pDel->next = q;
	}
	else
	{
		pListNode *pList;
		pList = *L;
		while(pList->next != pDel)
			pList = pList->next;
		pList->next = NULL;
		free(pDel);
	}
}

void insert(pListNode *L)
{
	int ele;
	pListNode *p,*q;
	p = L;

	while(1)
	{
		scanf("%d",&ele);
		if(ele == 0) break;
		q = (pListNode *)malloc(sizeof(pListNode));
		q->data = ele;
		q->next = p->next;
		p->next = q;
		p = q;
	}
}

void print(pListNode *L)
{
	L = L->next;
	while(L)
	{
		printf("%d  ",L->data);
		L = L->next;
	}
	printf("\n");
}

int main()
{
	pListNode *L,*pDel;
	int i = 0;	
	int j = 0;

	init(&L);
	insert(L);
	print(L);

	/*printf("please input delete which data:\n");
	scanf("%d",&i);
	
	pDel = L;
	for(j=1;j<=i;j++)
	{
		pDel = pDel->next;
	}

	deleteNode(&L,pDel);
	print(L);*/

	return 0;
}
