/* 使用函数计算1!+2!+3!+...+n! */
#include <stdio.h>
double fact(int n);

int main(void)
{
	int i,n;
	double sum;

	printf("enter n:");
	scanf("%d",&n);

	if(n==0)
	{
		sum=fact(n);
		printf("%d!=%e\n",n,sum);
	}
	else
	{
		sum=0;
		for(i=1;i<=n;i++)
			sum=sum+fact(i);

		printf("1!+2!+...+%d!=%e\n",n,sum);
	}

	return 0;
}

double fact(int n)
{
	int i;
	double result;

	result=1;
	for(i=1;i<=n;i++)
		result=result*i;

	return result;
}