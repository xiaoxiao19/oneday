//15.10.15
//search:顺序表-顺序查找

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[5] = {0};
	int i = 0;
	int key = 0;

	for(i=0;i<6;i++)
		scanf("%d",&a[i]);

	for(i=0;i<6;i++)
		printf("%d",a[i]);
	
	printf("scanf of the key!\n");
	scanf("%d",&key);

	for(i=0;i<6;i++)
		if(a[i] == key)
			printf("find the key:%d\n",i);

	return 0;
}
