/* 计算1+1/2+1/3+1/4+。。。共n项之和 */
#include <stdio.h>

int main(void)
{
	int i,n;
	double item,sum;

	printf("enter n:");
	scanf("%d",&n);

	sum=0;
	for(i=1;i<=n;i++)
	{
		item=1.0/i;
		sum=sum+item;
	}
	
	printf("sum=%f\n",sum);

	return 0;
}