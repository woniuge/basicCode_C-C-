/* 逆序输出一个整数 */
#include <stdio.h>
int reverse(int number);

int main(void)
{
	int number;

	printf("enter a number:");
	scanf("%d",&number);

	printf("%d",reverse(number));

	printf("\n");

	return 0;
}

int reverse(int number)
{
	int m,y=0;

	if(number>0)
		m=number;
	else
		m=-number;

	while(m!=0)
	{
		y=10*y+m%10;
		m=m/10;
	}

	if(number>=0)
		return y;
	else
		return -y;
}