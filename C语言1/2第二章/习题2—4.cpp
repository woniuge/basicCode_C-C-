/* 输入两个正整数m和n，计算和式(i^2+1/i)其中i从m逐一增大到n */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,m,n;
	double sum;

	printf("enter m:");
	scanf("%d",&m);
	printf("enter n:");
	scanf("%d",&n);

	sum=0;
	for(i=m;i<=n;i++)
	{
		sum=sum+pow(i,2)+pow(i,-1);
	}

	printf("sum=%f\n",sum);

	return 0;
}