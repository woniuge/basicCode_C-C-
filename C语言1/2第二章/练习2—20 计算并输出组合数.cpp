/* ����͵�����׳˺������㲢�������� */
#include <stdio.h>
double fact(int x);

int main(void)
{
	int i,n,m;
	double result;

	printf("enter n:");
	scanf("%d",&n);
	printf("enter m(m<=n):");
	scanf("%d",&m);

	result=fact(n)/(fact(m)*fact(n-m));

	printf("result(%d,%d)=%.0f\n",n,m,result);

	return 0;
}

/* ������n!�ĺ��� */
double fact(int x)
{
	int i;
	double product;

	product=1;
	for(i=1;i<=x;i++)
	{
		product=product*i;
	}

	return product;
}
