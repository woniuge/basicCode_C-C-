/* 从输入的一批以负数结束的成绩中选出最高分,用while语句实现 */
#include <stdio.h>

int main(void)
{
	double mark,max;

	printf("enter marks:");
	scanf("%lf",&mark);
	
	max=mark;
	while(mark>=0)
	{
		if(max<mark)
		max=mark;
		scanf("%lf",&mark);
	}

	printf("max=%.2lf\n",max);

	return 0;
}