/* Çó¾ø¶ÔÖµ */
#include <stdio.h>

int main(void)
{
	double number;

	printf("enter a number:");
	scanf("%lf",&number);

	if(number<=0)
		number=-number;
	
	printf("the absolute value is %f.\n",number);

	return 0;
}