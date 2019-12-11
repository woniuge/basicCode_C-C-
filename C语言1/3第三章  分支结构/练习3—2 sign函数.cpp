/* signº¯Êý */
#include <stdio.h>

int main(void)
{
	double x;
	int y;

	printf("enter x:");
	scanf("%lf",&x);

	if(x<0)
	{
		y=-1;
	}
	else if(x>0)
	{
		y=1;
	}
	else
	{
		y=0;
	}

	printf("y=sign(%f)=%d\n",x,y);

	return 0;
}
