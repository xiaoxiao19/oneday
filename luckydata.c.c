/*
题目描述：
两个函数：
fx = x这个数用十进制写出后各个位数上的数字之和，如：f123 = 1+2+3=6
gx = 表示把x这个数用二进制写出后各个位数上的数字之后，如：123的二进制位1111011，那么g123=6
求所有的小于数字n的数中满足fx=gx的数的个数

例如：
输入：
3  （给出的样例个数）
 1
 5
 21
 输出：
 1
 1
 3
*/


#include <stdio.h>
#include <stdlib.h>

int NumberOf1(int n)
{
  int count = 0;
  while(n)
  {
    ++count;
    n = (n-1)&n;
  }
  return count;
}

int sum(int n)
{
  int sum = 0;
  do  
  {
    sum += n%10;
  }while((n/=10) > 0);
  return sum;
}

int main()
{
  int i;
  int j = 0;
  int count;
  int number[] = {0};
  int res[] = {0};//这里貌似是只初始化了res[0],而没有初始化接下来的 

  scanf("%d",&count);
  for(i=0;i<count;i++)
  {
    scanf("%d",&number[i]);
    while(number[i] >0)
    {
      if(sum(number[i]) == NumberOf1(number[i]))
      {
        res[j] += 1;
      }
      number[i]--;
    }
    printf("j:%d  res[j]:%d\n",j,res[j]);
    j++; 
    res[j] = 0;//没有这句的话,最后的结果会出现错误
  }

  int m = 0;
  for(m=0;m<j;m++)
    printf("%d\n",res[m]);
}
