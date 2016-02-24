//15.9.22
/*
使用两个栈实现一个队列
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int data;
	struct stack *next;
}Stack;

void init(Stack **s)
{
	(*s) = (Stack *)malloc(sizeof(Stack));
	(*s)->next = NULL;
}

void push(Stack *s,int ele)
{
	Stack *p;
	
	p = (Stack *)malloc(sizeof(Stack));
	p->data = ele;
	p->next = s->next;
	s->next = p;
}

int pop(Stack *s)
{
	Stack *p;
	p = s->next;
	int res = 0;
	
	if(p == NULL)
		printf("the stack is null!\n");
	else
	{
		s->next = p;
		//printf("the pop data is:%d\n",p->data);
		res = p->data;
		//free(p);//注意这里，要是将p释放的话，结果就会出现错误
		return res;
	}
	return 0;
}

void insertList(Stack *pushStack,int data)
{
	//入队

	push(pushStack,data);
}

void deleteList(Stack *pushStack,Stack **popStack)
{
	int popRes = 0;
	
	//出队

	if((*popStack)->next == NULL)
		while(pushStack->next)
		{
			popRes = pop(pushStack);
			push((*popStack),popRes);
			pushStack = pushStack->next;
		}

	//while(pushStack->next)
	//{
		popRes = pop((*popStack));
		(*popStack) = (*popStack)->next;
		printf("::%d\n",popRes);
	//}
}

int main()
{
	Stack *s;
	Stack *s1;

	init(&s);
	init(&s1);

	int data = 0;

	init(&s);

	while(1)
	{
		scanf("%d",&data);
		if(data == 0)  break;
		insertList(s,data);
	}

	while(s->next)
	{
		deleteList(s,&s1);
		s = s->next;
	}

	return 0;
}

