/* 计算1-1/4+1/7-1/10+1/13-1/16+。。。共n项之和 */
#include <stdio.h>

int main(void)
{
	int i,n,flag,denominator;
	double item,sum;

	printf("enter n:");
	scanf("%d",&n);

	flag=1;
	denominator=1;
	sum=0;

	for(i=1;i<=n;i++)
	{	
		item=flag*1.0/denominator;
		sum=sum+item;
		flag=-flag;
		denominator=denominator+3;
	}

	printf("sum=%f\n",sum);

	return 0;
}
