/* ����x��n�η� ���������pow()�������� */
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