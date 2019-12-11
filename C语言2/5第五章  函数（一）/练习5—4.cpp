#include <stdio.h>
double max(double a,double b);

int main (void)
{
	double a,b,c;

	printf("enter a and b:");
	scanf("%lf%lf",&a,&b);

	c=max(a,b);

	printf("the max of %lf and %lf is %lf.\n",a,b,c);

	return 0;
}

double max(double a,double b)
{
	double max;

	if(a>b)
		max=a;
	else
		max=b;

	return max;
}