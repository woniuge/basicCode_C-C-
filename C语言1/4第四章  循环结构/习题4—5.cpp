/* ��������������a��n����a+aa+aaa+...+aa...a��n��a��֮�͡� */
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