/* 输入一批正整数（以零或负数作为结束标志），求其中的偶数和 */
#include <stdio.h>

int main(void)
{
	int number;
	double sum;

	printf("enter numbers:");
	scanf("%d",&number);

	if(number<=0);
	else
	{
		sum=0;
		while(number>0)
		{
			if(number%2==0)
				sum=sum+number;
			scanf("%d",&number);
		}

		printf("sum=%.1lf\n",sum);
	}

	return 0;
}