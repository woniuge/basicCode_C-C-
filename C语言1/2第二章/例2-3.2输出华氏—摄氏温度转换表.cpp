#include <stdio.h>

int main(void)
{
	int fahr,lower,upper;
	double celsius;

	printf("enter lower:");
	scanf("%d",&lower);
	printf("enter upper:");
	scanf("%d",&upper);
	printf("fahr celsius\n");

	for(fahr=lower;fahr<=upper;fahr++)
	{
		celsius=(5.0/9.0)*(fahr-32);
		printf("%d%6.1f\n",fahr,celsius);
	}
	return 0;
}