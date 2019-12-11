#include <stdio.h>
int sign(double x);

int main(void)
{
	double x;

	printf("enter x:");
	scanf("%lf",&x);

	printf("f(%lf)=%d\n",x,sign(x));

	return 0;
}

int sign(double x)
{
	if(x>0)
		return 1;
	else
		if(x==0)
			return 0;
		else
			return -1;
}