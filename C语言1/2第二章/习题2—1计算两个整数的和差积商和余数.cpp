/* 计算两个整数的和差积商和余数 */
#include <stdio.h>

int main(void)
{
	int num1,num2;
	int sum,difference,product,remainder;
	double quotient;

	printf("enter num1:");
	scanf("%d",&num1);
	printf("enter num2:");
	scanf("%d",&num2);

	sum=num1+num2;
	difference=num1-num2;
	product=num1*num2;
	quotient=num1*1.0/num2;
	remainder=num1%num2;
	
	printf("sum=%d\ndifference=%d\nproduct=%d\nquotient=%.2f\nremainder=%d\n",sum,difference,product,quotient,remainder);

	return 0;
}