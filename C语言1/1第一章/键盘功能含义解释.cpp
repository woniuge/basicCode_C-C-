#include<stdio.h>

int main(void)
{
	int i;
	printf("hello begin test ######\n");

	for(i=0;i<=128;i++)
		printf("@@@@%3d$$$$[%02x]!!!!(%c)&&&&\n",i,i,i);

	printf("hi end test ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");

	return 0;
}
