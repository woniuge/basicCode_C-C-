#include <stdio.h>
#include <math.h>

int main(void)
{
	double x,y;

	printf("enter x:\n");
	scanf("%lf",&x);

	if(x<0)
	{
		y=pow(x,5)+2*pow(x,1)+pow(x,-1);
	}
	else
	{
		y=sqrt(x);
	}

	printf("y=f(%f)=%.2f\n",x,y);

	return 0;
}
