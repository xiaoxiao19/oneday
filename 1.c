//15.9.12
/*
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序，
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数？
*/

#include <stdio.h>
#include <stdlib.h>

#define N 100

int find(int arr[][N],int w,int h,int i)//zhongdian:arr[N][N]???!!!
{
	if(w>4 || h<0)
		return 0;

	if(i == arr[w][h])
		return 1;
	else if(i>arr[w][h])
		return find(arr,w+1,h,i);////
	else
		return find(arr,w,h-1,i);///

}

int main()
{
	int array[N][N] = {0};
	int w = 0;
	int h = 0;
	int a = 0;
	int b = 0;
	int num = 0;
	int result = 0;
	
	printf("please input hengzuobiao:\n");
	scanf("%d",&w);
	printf("please input zongzuobiao:\n");        
	scanf("%d",&h);

	for(a=0;a<w;a++)
	{
		for(b=0;b<h;b++)
			scanf("%d",&array[a][b]);
	}

	printf("please input number:\n");
	scanf("%d",&num);

	result = find(array,0,h-1,num);

	if(result == 1)
	{
		printf("can find\n");
	}
	else
	{
		printf("can not find\n");
	}

	return 0;
}
