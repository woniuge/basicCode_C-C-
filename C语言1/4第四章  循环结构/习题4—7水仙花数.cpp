/* 求1~10000之间所有满足各位数字的立方和等于它本身的数 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,n,x,temp,sum;

	printf("enter n:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		x=i;

		sum=0;
		while(x!=0)
		{
			temp=x%10;
			sum=sum+pow(temp,3);
			x=x/10;
		}

		if(sum==i)
			printf("%4d",i);
	}

	printf("\n");

	return 0;
}