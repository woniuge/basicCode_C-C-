/* 统计一个整数的位数 */
#include <stdio.h>

int main(void)
{
	int count,number;							/* count记录整数number的位数 */

	printf("enter a number:");
	scanf("%d",&number);

	count=0;
	if(number<0)
		number=-number;
	do{
		number=number/10;
		count++;
	}while(number!=0);							/* 判断循环条件 */

	printf("It contains %d digits.\n",count);

	return 0;
}