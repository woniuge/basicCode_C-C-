/* �ж����ֵ���ż�� */
#include <stdio.h>

int main(void)
{
	int number;

	printf("enter a number:");
	scanf("%d",&number);

	if(number%2==0)
		printf("the number is even.\n");	/* even ż�� */
	else
		printf("the number is odd.\n");		/* odd ���� */

	return 0;
}