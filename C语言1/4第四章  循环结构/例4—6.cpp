/* 使用嵌套循环计算1!+2!+3!+...+n! */
#include <stdio.h>

int main(void)
{
	int i,j,n;
	double item,sum;

	printf("enter n:");
	scanf("%d",&n);

	if(n==0)
	{
		sum=0;
		item=1;
		for(j=1;j<=i;j++)
		item=item*j;
		sum=sum+item;
		
		printf("%d!=%e\n",n,sum);
	}
	else
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			item=1;
			for(j=1;j<=i;j++)
			item=item*j;
			sum=sum+item;
		}

		printf("1!+2!+...+%d!=%e\n",n,sum);
	}

	return 0;
}
