/* 输入一个长整数，从高位开始逐位分割并输出。 */
#include <stdio.h>

int main(void)
{
	int i,j,n,first;
	int a[20];

	for(i=0;i<20;i++)
		a[i]=0;

	printf("input an integer:");
	scanf("%d",&n);
	
	i=1;
	while(n!=0)
	{
		a[i]=n%10;
		n=n/10;
		i++;
	}

	first=1;
	for(j=i-1;j>0;j--)
	{
		if(first)
			first=0;
		else
			printf(" ");

		printf("%d",a[j]);
	}

	printf("\n");

	return 0;
}