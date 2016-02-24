//15.9.22
/*
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出序列。假设压入栈的所有数字均不相等。例如序列1、2、3、4、5是某栈的压栈序列，序列4、5、3、2、1是该栈序列对应的一个弹出序列，但4、3、5、1、2就不可能是该压栈序列的弹出序列。
*/

#include <stdio.h>
#include <stdlib.h>

int decide(int pushArr[],int popArr[],int nLen)
{
	int curArr[5] = {0};
	int curPush = -1;
	int curPop = 0;
	int i = -1;

	while(curPop < nLen)
	{
		while((i == -1 || curArr[i] != popArr[curPop]) && curPush < nLen-1)
		{
			curArr[++i] = pushArr[++curPush];
		}
	
		if(curArr[i] == popArr[curPop])
		{
			curPop--;
			i--;
			continue;
		}
		
		if(curPush == nLen-1)
			return 0;
	}
	
	return 1;
}

int main()
{
	int pushArr[] = {1,2,3,4,5};
	int popArr[] = {4,5,3,2,1};
	int res = 0;

	res = decide(pushArr,popArr,5);
	
	if(res == 1)
		printf("Yes!\n");
	else
		printf("No!\n");

	return 0;
}
