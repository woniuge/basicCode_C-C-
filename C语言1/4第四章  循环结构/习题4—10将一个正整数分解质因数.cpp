/* 将一个正整数分解质因数。例如，输入90，输出90=2*3*3*5 */
#include <stdio.h>
#include <math.h>
int prime(int n);

int main(void)
{
	int i,n,first;

	printf("enter n:");
	scanf("%d",&n);

	if(prime(n)==n||n==1)
		printf("%d",n);
	else
	{
		first=1;
		for(i=2;i<=n;i++)
		{
			while(n%i==0)
			{
				if(first)
				{
					printf("%d=%d",n,i);
					first=0;
				}
				else
					printf("*%d",i);

				n=n/i;
			}
		}
	}

	printf("\n");

	return 0;
}

int prime(int n)
{
	int i,prime;

	if(n<=1);
	else
		{
			for(i=2;i<=sqrt(n);i++)
				if(n%i==0)
					break;
			if(i>sqrt(n))
				prime=n;
		}

	return prime;
}
