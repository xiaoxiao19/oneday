//15.10.15
//search-分块查找-blocking search

#include <stdio.h>
#include <stdlib.h>

typedef struct index
{
	int m;
	int data;
}Index;

int search(Index index[2],int b[17],int key)
{
	int j = 0;
	int k = 0;

	while(j < 3 && key >= index[j].data)
			j++;

	if(j >= 3)
		return 0;

	for(k=index[j].m;k<18;k++)
	{
		if(key == b[k])
			return k;
	}
	return 0;
}

int main()
{
	Index index[2];
	int b[17] = {0};
	int result = 0;
	int key = 0;
	int i = 0;

	printf("print the block:\n");
	for(i=0;i<3;i++)
		scanf("%d,%d",&index[i].m,&index[i].data);

	printf("print the data:\n");
	for(i=0;i<18;i++)	
		scanf("%d",&b[i]);

	printf("print the key:\n");
		scanf("%d",&key);

	result = search(index,b,key);

	printf("result is:%d\n",result);

	return 0;
}
