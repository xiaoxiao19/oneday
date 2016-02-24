/*15.9.15
从尾到头打印链表：
输入一个链表的头结点，从尾到头反过来打印出每个节点的值。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}pLNode;


void init_LNode(pLNode **l)
{
	*l = (pLNode *)malloc(sizeof(pLNode));
	(*l)->next = NULL;
}

void reverse(pLNode *L)
{
	if(L->next)
		reverse(L->next);
	printf("%d  ",L->data);
}

void insert_back(pLNode *L)
{
    int data;
    scanf("%d",&data);
    while(data != 0)
    {
        if(data != 0)//注意这里边三句话的顺序，不能讲L =L->next;放在分配内存前，这样L会为空
        {
            L->next = (pLNode *)malloc(sizeof(pLNode));
            L = L->next;
            L->data = data;
        }
        scanf("%d",&data);
    }
}

void search(pLNode **L)
{
	int j = 0;

	for(j=1;j<=3;j++)
	{
		*L = (*L)->next;
	}
}

void insert_former(pLNode *L)
{
	int e;
	pLNode *p;

	while(1)
	{
		scanf("%d",&e);
		if(e == 10)
			break;
		p = (pLNode *)malloc(sizeof(pLNode));
		p->data = e;
		p->next = L->next;
		L->next = p;
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

int main()
{
	pLNode *l;

	init_LNode(&l);
	insert_back(l);
	print(l);

	search(&l);
	print(l);

	reverse(l->next);

	printf("\n");
	
	return 0;
}
