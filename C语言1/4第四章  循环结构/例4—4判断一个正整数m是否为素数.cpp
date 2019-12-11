/* 判断一个正整数m是否为素数 */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,m;

	printf("enter a number:");
	scanf("%d",&m);

	if(m==1)
			printf("No!\n");
	else
	{
		for (i=2;i<=sqrt(m);i++)
			if(m%i==0)
				break;							/* 若m能被某个i整除，则m不是素数，提前结束循环 */
		if(i>sqrt(m))							/* 如果循环正常结束，说明m不能被任何一个i整除，则m是素数 */
			printf("%d is a prime number!\n",m);
		else
			printf("No!\n");
	}

	return 0;
}