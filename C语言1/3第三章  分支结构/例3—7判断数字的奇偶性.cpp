/* 判断数字的奇偶性 */
#include <stdio.h>

int main(void)
{
	int number;

	printf("enter a number:");
	scanf("%d",&number);

	if(number%2==0)
		printf("the number is even.\n");	/* even 偶数 */
	else
		printf("the number is odd.\n");		/* odd 奇数 */

	return 0;
}