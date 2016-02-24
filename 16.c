//15.9.24
/*
重建二叉树：输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树，假设输入的前序遍历和中序遍历的结果中都不包含重复的数字，例如输入前序遍历序列1、2、4、7、3、5、6、8和中序遍历序列4、7、2、1、5、3、8、6，则重建出如果所示的二叉树并输出它的头结点，二叉树按照二叉链表建立结点。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int data;
	struct tree *LChild;
	struct tree *RChild;
}Tree;

Tree *construct(int PreOrder[],int preStart,int preEnd,int InOrder[],int InStart,int InEnd)
{
	int root = 0;
	
	if(InStart > InEnd)
		return NULL;

	root = PreOrder[preStart];

	int count = 0;
	int i = 0;

	for(i=InStart;i<InEnd;i++)//
	{
		if(root != InOrder[i])
			count++;
		else
			break;
	}
	
	Tree *t;
	t = (Tree *)malloc(sizeof(Tree));
	t->data = root;
	t->LChild = construct(PreOrder,preStart+1,preStart+count,InOrder,InStart,InStart+count-1);
	t->RChild = construct(PreOrder,preStart+count+1,preEnd,InOrder,InStart+count+1,InEnd);
	return t;
}

void preOrderTree(Tree *t)
{
	if(t)
	{
		printf("%d  ",t->data);
		preOrderTree(t->LChild);
		preOrderTree(t->RChild);
	}
	//printf("\n");
}

int main()
{
	Tree *t;

	int PreOrder[8] = {1,2,4,7,3,5,6,8};
	int InOrder[8] = {4,7,2,1,5,3,8,6};

	t = construct(PreOrder,0,7,InOrder,0,7);

	preOrderTree(t);
	printf("\n");

	return 0;
}
