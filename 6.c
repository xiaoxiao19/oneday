//15.9.18
/*
输入一个链表，输出该链表中倒数第k个结点。为了符合大多数人的习惯，本体从1开始计数，即链表的尾结点是倒数第1个结点，例如一个链表有6个结点，从头结点开始他们的值依次是1、2、3、4、5、6，这个链表的倒数第3个结点的值为4的结点：
struct ListNode	
{
	int m_nValue;
	ListNode *m_pNext;
};


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode 
{
	int data;
	struct LNode *next;
}pLNode;

void init(pLNode **L)
{
	*L = (pLNode *)malloc(sizeof(pLNode));
	(*L)->next = NULL;
}

void insert(pLNode *l)
{
	pLNode *p;
	int ele = 0;
	
	while(1)
	{
		scanf("%d",&ele);
		if(ele == 0) break;
		p = (pLNode *)malloc(sizeof(pLNode));
		p->data = ele;
		p->next = l->next;
		l->next = p;
		l = p;
	}
}

void search(pLNode *l,int num)
{
	int i = 0;
	pLNode *p,*q;
	p = l->next;
	q = l->next;
	
	printf("%d\n",num);

	while(i < num-1)
	{	
		p = p->next;
		i++;
	}
	
	while(p->next)
	{
		p = p->next;
		q = q->next;
	}
	printf("%d\n",q->data);
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

	init(&L);
	insert(L);
	print(L);

	search(L,3);

	return 0;
}
