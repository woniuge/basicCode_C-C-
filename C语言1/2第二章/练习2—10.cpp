#include <stdio.h>

int main(void)
{
	double x,y;

	printf("enter x= \n");
	scanf("%lf",&x);

	if(x!=0)
	{
		y=1/x;
	}
	else
	{
		y=0;
	}

	printf("y=f(%lf)=%.3f\n",x,y);

	return 0;
}