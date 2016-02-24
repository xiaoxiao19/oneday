/*15.9.14
替换空格：请实现一个函数，把字符串中的每个空格替换成“%20”，例如：
输入“we are happy”，则输出“we%20are%20happy”
*/

#include <stdio.h>
#include <stdlib.h>

void replace(char arr[])
{
	int nOfBlank = 0;
	int nOfNewLen = 0;
	int nOfOldLen = 0;
	char *parr = arr;
	char *pNewarr = NULL;

	if(parr == NULL)
		return;

	while(*parr)//?????
	{
		nOfOldLen++;
		if(*parr == ' ')
		{
			nOfBlank++;
		}
		parr++;
	}

	nOfNewLen = nOfBlank * 2 + nOfOldLen;

	pNewarr = arr + nOfNewLen -1;
	parr = arr + nOfOldLen - 1;

	while(0 != nOfOldLen)////
	{
		if(*parr != ' ')////
		{
			*pNewarr = *parr;
		}
		else
		{
			*pNewarr = '0';
			pNewarr--;
			*pNewarr = '2';
			pNewarr--;
			*pNewarr = '%';
		}
		nOfOldLen--;
		parr--;
		pNewarr--;////
	}

	pNewarr[nOfNewLen+1] = 0;
	puts(pNewarr);
	puts(parr);
}

int main()
{
	char arr[20];
	printf("please input the string:\n");
	gets(arr);
	puts(arr);
	printf("the replaced string is:\n");
	replace(arr);
	printf("%s\n",arr);;
	return 0;
}
