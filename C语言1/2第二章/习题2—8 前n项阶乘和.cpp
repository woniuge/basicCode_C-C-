/* З°nПоЅЧіЛєН0!+1!+2!+3!+... */
#include <stdio.h>
double fact(int n);

int main(void)
{
	int i,n;
	double sum;

	printf("enter n:");
	scanf("%d",&n);

	sum=0;
	for(i=0;i<=n;i++)
	{
		sum=sum+fact(i);
	}

	printf("%.0f\n",sum);

	return 0;
}

double fact(int n)
{
	int i;
	double product;

	product=1;
	for(i=1;i<=n;i++)
	{
		product=product*i;
	}
	return product;
}