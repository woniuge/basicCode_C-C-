/* 计算x的n次方 不允许调用pow()函数求幂 */
#include <stdio.h>

int main(void)
{
	int i,n;
	double x,product,y;

	printf("enter x:");
	scanf("%lf",&x);
	printf("enter n:");
	scanf("%d",&n);

	product=1;
	for(i=1;i<=n;i++)
	{
		product=product*x;
	}

	printf("y=product(%f,%d)=%.2f\n",x,n,product);

	return 0;
}