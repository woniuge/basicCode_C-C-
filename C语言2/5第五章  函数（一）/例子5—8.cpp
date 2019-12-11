#include <stdio.h>
void fun(int k);

int main(void)
{
	int k;
	for(k=1;k<=3;k++)
		fun(k);

	printf("\n");

	return 0;
}

void fun(int k)
{
	static int a;

	printf("%d,",a);
	a+=k;				/* a+=k±íÊ¾a=a+k */
}