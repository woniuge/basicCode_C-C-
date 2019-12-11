/* 计算1-2/3+3/5-4/7+5/9-6/11+...的前n项之和 */
#include <stdio.h>

int main(void)
{
	int i,n,flag,denominator;
	double item,sum;

	printf("enter n:");
	scanf("%d",&n);

	sum=0;
	flag=denominator=1;
	for(i=1;i<=n;i++)
	{	
		item=flag*i*1.0/denominator;
		sum=sum+item;
		flag=-flag;
		denominator=denominator+2;
	}

	printf("sum=%f\n",sum);

	return 0;
}