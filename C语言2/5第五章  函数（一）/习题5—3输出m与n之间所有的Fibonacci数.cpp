/* 输出m与n之间所有的Fibonacci数 */
#include <stdio.h>
int fib(int n);

int main(void)
{
	int m,n,i;

	printf("enter m and n(1<=m<=n<=10000):");
	scanf("%d%d",&m,&n);

	int first=1;
	for(i=m;i<=n;i++)
		for(int j=1;j<=i+1;j++)
		{
			if(i==fib(j))
			{
				if(first)
					first=0;
				else
					printf(" ");
				printf("%d",i);
			}
		}

	printf("\n");

	return 0;
}

int fib(int n)
{
	int x1,x2,x;

	if(n==1||n==2)
		return 1;
	else
	{
		x1=x2=1;
		for(int i=1;i<=n-2;i++)
		{
			x=x1+x2;
			x1=x2;
			x2=x;
		}
		return x;
	}
}