//15.9.24
/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数，在该栈中，调用min、push、pop的时间复杂度都是O(1)
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
	(*s)->data = 0;
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
	int popEle = 0;

	p = s->next;
	popEle = p->data;
	s->next = p->next;
	free(p);
	return popEle;
}

void print(Stack *s)
{
	s =s->next;
	while(s)
	{
		printf("%d  ",s->data);
		s = s->next;
	}
	printf("\n");
}

void min(Stack *s,Stack *p,int ele)
{
	if(s->next)
	{
		if(ele < p->next->data)//p->next->data not s->next->data!!!
			push(p,ele);
	}
	else
		push(p,ele);
}

int main()
{
	Stack *s;
	Stack *minStack;
	int ele = 0;
	int minEle = 0;
		
	init(&s);
	init(&minStack);
	
	while(1)
	{
		scanf("%d",&ele);
		if(ele == 0)   break;
		min(s,minStack,ele);
		push(s,ele);
	}

	//print(s);
	//pop(s);
	//print(s);

	minEle = pop(minStack);
	printf("the min is:%d\n",minEle);

	return 0;
}
