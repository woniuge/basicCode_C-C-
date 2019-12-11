/* 输出m与n之间所有的完数(因子和等于其本身) */
#include <stdio.h>
int factorsum(int number);

int main(void)
{
	int m,n,i;

	printf("enter m and n(1<=m<=n<=1000):");
	scanf("%d%d",&m,&n);

	int first=1;
	for(i=m;i<=n;i++)
	{
		if(i==factorsum(i))
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

int factorsum(int number)
{
	int i,sum;

	sum=0;
	for(i=1;i<=(number+1)/2;i++)
		if(number%i==0)
			sum=sum+i;

	return sum;
}