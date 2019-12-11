/* 输出m与n之间所有的水仙花数(各位数字的立方和等于其本身) */
#include <stdio.h>
#include <math.h>
int is(int number);

int main(void)
{
	int m,n,i;

	printf("enter m and n(1<=m<=n<=1000):");
	scanf("%d%d",&m,&n);

	int first=1;
	for(i=m;i<=n;i++)
		if(is(i))
		{
			if(first)
				first=0;
			else
				printf(" ");
			printf("%d",i);
		}

	printf("\n");
	return 0;
}

int is(int number)
{
	int item,temp,sum=0;
	
	item=number;
	while(item!=0)
	{
		temp=item%10;
		sum=sum+pow(temp,3);
		item=item/10;
	}

	if(sum==number)
		return 1;
}