//15.10.15
//search:顺序表-折半查找

#include <stdio.h>
#include <stdlib.h>

int search()
{
	int a[5] = {0};
	int i = 0;
	int low = 0;
	int high = 6;
	int mid = 0;
	int key = 0;
	
	printf("scanf the key:\n");
	scanf("%d",&key);

	for(i=0;i<6;i++)
		scanf("%d",&a[i]);

	while(low < high)
	{
		mid = (low + high)/2;
		if(a[mid] == key)
		{
			return mid;
		}
		else if(a[mid] > key)
			high = mid-1;
		else
			low = mid+1;
	}
	return 0;
}

int main()
{
	int result = 0;

	result = search();
	printf("result is:%d\n",result);

	return 0;

}
