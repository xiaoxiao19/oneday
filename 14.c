//15.9.22
/*
使用两个队列实现一个栈结构
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
	int data;
	struct queue *next;
}Queue;

typedef struct qpointer
{
	Queue *front;
	Queue *rear;
}Qpointer;

void init(Qpointer **q)
{
	(*q) = (Qpointer *)malloc(sizeof(Qpointer));

	(*q)->front = (Queue *)malloc(sizeof(Queue));
	(*q)->front->next = NULL;
	(*q)->rear = (*q)->front;	
}

void insertQueue(Qpointer *q,int ele)
{
	Queue *queue;

	queue = (Queue *)malloc(sizeof(Queue));
	queue->data = ele;
	queue->next = NULL;
	q->rear->next = queue;
	q->rear = queue;
}

int  deleteQueue(Qpointer *q)
{
	if(q->front)
	{
		q->front = q->front->next;
		//free(q->front);
		return q->front->data;	
	}
	return 0;
}

void push(Qpointer *q,int ele)
{
	insertQueue(q,ele);
}

void pop(Qpointer *qPush,Qpointer *qPop)
{
	int ele = 0;

	//如果队列pop为空，则将push中的除了最后一个元素之外的所有元素插入到qPop队列中
	if(qPop->front == qPop->rear)
	{
		while(qPush->front->next->next)//
		{
			ele = deleteQueue(qPush);
			//printf("::%d\n",ele);
			insertQueue(qPop,ele);
		}
		ele = deleteQueue(qPush);
		printf(":::%d\n",ele);
	}
	//否则，将插入到qPop队列中的除最后一个元素之外的所有元素插入到qPush队列中
	else if(qPush->front == qPush->rear)
	{
		while(qPop->front->next->next)//
		{
			ele = deleteQueue(qPop);
			//printf("::%d\n",ele);
			insertQueue(qPush,ele);
		}
		ele = deleteQueue(qPop);
		printf(":::%d\n",ele);
	}
}

void print(Qpointer *q)
{
	q->front = q->front->next;

	while(q->front)
	{
		printf("%d  ",q->front->data);
		q->front = q->front->next;
	}
	printf("\n");
}

int main()
{
	Qpointer *q,*q1;
	int data = 0;
	int count = 0;
	int i = 0;

	init(&q);
	init(&q1);

	while(1)
	{
		scanf("%d",&data);
		if(data == 0)   break;
		push(q,data);
		count++;
	}
	//print(q);
	for(i = 0;i<count;i++)
		pop(q,q1);
	//print(q);

	return 0;
}

