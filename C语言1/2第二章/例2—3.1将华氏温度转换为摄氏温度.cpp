#include <stdio.h>
int main(void)
{
	int celsius,fahr;

	printf("enter fahr:");
	scanf("%d",&fahr);

	celsius=5*(fahr-32)/9;

	printf("fahr=%d,celsius=%d\n",fahr,celsius);

	return 0;
}