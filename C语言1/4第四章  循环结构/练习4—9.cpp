/* 完善从输入的n个成绩中选出最高分，用for语句实现 */
#include <stdio.h>

int main(void)
{
	int i,n;
	double mark,max;

	printf("enter n:");
	scanf("%d",&n);

	if(n<=0);
	else
	{
		printf("enter %d marks:",n);
		scanf("%lf",&mark);

		max=mark;
		for(i=1;i<n;i++)
		{
			scanf("%lf",&mark);
			if(max<mark)
				max=mark;
	}

	printf("max=%.2lf\n",max);
	}

	return 0;
}