#include <stdio.h>

int main(void)
{
	double a,b,c;
	double average;

	printf("enter a, b, c, =\n");
	scanf("%lf%lf%lf",&a,&b,&c);

	average=(a+b+c)/3;

	printf("average=%lf\n",average);

	return 0;
}