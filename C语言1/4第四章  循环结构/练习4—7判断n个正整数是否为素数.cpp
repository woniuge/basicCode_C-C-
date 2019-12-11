/* 判断n个正整数是否为素数 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,j,n,number;

	printf("enter n:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("enter number(>0) #%d:",i);
		scanf("%d",&number);

		if(number==1)
			printf("No!\n");
		else
		{
			for(j=2;j<=sqrt(number);j++)
				if(number%j==0)
					break;
			if(j>sqrt(number))
				printf("%d is a prime number!\n",number);
			else
				printf("No!\n");
		}
	}
	
	return 0;
}