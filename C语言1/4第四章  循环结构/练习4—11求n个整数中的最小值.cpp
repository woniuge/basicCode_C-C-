/* 求n个整数中的最小值 */
#include <stdio.h>

int main(void)
{
	int i,n;
	double number,min;

	printf("enter n:");
	scanf("%d",&n);

	if(n<=0);
	else
	{
		printf("enter %d numbers:",n);
		scanf("%lf",&number);

		min=number;
		for(i=1;i<n;i++)
			scanf("%lf",&number);
			if(min>number)
				min=number;

		printf("Min=%lf\n",min);
	}

	return 0;
}