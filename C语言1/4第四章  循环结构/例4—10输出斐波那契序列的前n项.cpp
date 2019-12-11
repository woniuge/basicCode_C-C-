/* 输出斐波那契序列:1,1,2,3,5,8,13,...的前n项 */
#include <stdio.h>

int main(void)
{
	int i,n,x1,x2,x;

	printf("enter n:");
	scanf("%d",&n);

	x1=x2=1;
	printf("%6d%6d",x1,x2);
	for(i=1;i<=n-2;i++)
	{
		x=x1+x2;
		printf("%6d",x);
		x1=x2;
		x2=x;
	}

	printf("\n");

	return 0;
}