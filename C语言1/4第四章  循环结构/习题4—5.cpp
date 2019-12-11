/* 输入两个正整数a和n，求a+aa+aaa+...+aa...a（n个a）之和。 */
#include <stdio.h>

int main(void)
{
	int i,a,n;
	double item,sum;

	printf("enter a:");
	scanf("%d",&a);
	printf("enter n:");
	scanf("%d",&n);

	item=sum=0;
	for(i=1;i<=n;i++)
	{
		item=10*item+a;
		sum=sum+item;
	}

	printf("sum=%.2lf\n",sum);

	return 0;
}