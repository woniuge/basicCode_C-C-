/* 输入一批正整数（以零或负数为结束标志），求其中的奇数和。要求定义
和调用函数even（n）判断数的奇偶性，当n为偶数时返回1，否则返回0. */
#include <stdio.h>
int even(int n);

int main(void)
{
	int n,sum=0;

	printf("enter digits:");
	scanf("%d",&n);

	if(n<=0)
		printf("No!\n");
	else
	{
		while(n>0)
		{
			if(even(n)==0)
				sum=sum+n;
			scanf("%d",&n);
		}

		printf("the sum of odd is %d.\n",sum);
	}

	return 0;
}

int even(int n)
{
	if(n%2==0)
		return 1;
	else
		return 0;
}
