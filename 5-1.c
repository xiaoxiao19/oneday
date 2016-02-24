//15.9.17
/*
有一个人准备开始爬楼梯，假设楼梯有n个，这个人最多允许一次爬m个楼梯，请问有多少种爬法？
*/

#include <stdio.h>

int count(int n,int m)
{
	int sum = 0;
	int i = 0;

	if(n == 0)
		sum = 1;
	if(n>=m)
	{
		for(i=1;i<=m;i++)
			sum += count(n-i,m);
	}
	else
		sum = count(n,n);
	return sum;
}


int main()
{
	int n = 0;
	int m = 0;
	int result;

	printf("please input the number of n:\n");
	scanf("%d",&n);

	printf("please input the number of m:\n");
	scanf("%d",&m);

	result = count(n,m);
	printf("the result is:%d\n",result);

	return 0;
}
