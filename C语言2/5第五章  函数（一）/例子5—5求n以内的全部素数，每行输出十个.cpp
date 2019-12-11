/* 求n以内的全部素数，每行输出十个。要求定义和调用函数prime（m）
判断m是否为素数，当m为素数时返回1，否则返回0. */
#include <stdio.h>
#include <math.h>
int prime(int m);

int main(void)
{
	int i,n,count=0;

	printf("enter n:");
	scanf("%d",&n);

	for(i=2;i<=n;i++)
		if(prime(i))
		{
			printf("%4d",i);
			count++;
			if(count%10==0)
				printf("\n");
		}

	printf("\n");

	return 0;
}

int prime(int m)
{
	int i;

	if(m<=1)
		return 0;
	else
		for(i=2;i<=sqrt(m);i++)
		if(m%i==0)
			return 0;

	return 1;
}
