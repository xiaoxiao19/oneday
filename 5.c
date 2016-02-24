//15.9.17
/*
有一个人准备开始爬楼梯，假设楼梯有n个，这个人只允许一次爬一个楼梯或者一次爬两个楼梯，请问有多少种爬法？
*/

#include <stdio.h>

int count(int i)
{
	int sum = 0;

	if(i == 1)
		sum = 1;
	if(i == 2)
		sum = 2;
	if(i > 2)
		sum = count(i-1)+count(i-2);
	return sum;
}

int main()
{
	int n;
	int result;
	
	printf("please input the number of n:\n");
	scanf("%d",&n);

	result = count(n);
	printf("result is:%d\n",result);	

	return 0;
}
