/* 使用嵌套循环计算e=1+1/1!+1/2!+1/3!+...+1/n! */
#include <stdio.h>

int main(void)
{
	int i,j,n;
	double item,denominator,sum;

	printf("enter n:");
	scanf("%d",&n);

	sum=0;
	for(i=0;i<=n;i++)
	{
		denominator=1;
		for(j=1;j<=i;j++)
		{
			denominator=denominator*j;
		}
		item=1/denominator;
		sum=sum+item;	
	}

	printf("e=1+1/1!+1/2!+1/3!+...+1/%d!=%.2lf\n",n,sum);

	return 0;
}