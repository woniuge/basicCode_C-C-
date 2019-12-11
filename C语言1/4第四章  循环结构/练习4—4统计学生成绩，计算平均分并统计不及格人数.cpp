/* 统计学生成绩，计算平均分并统计不及格人数 */
#include <stdio.h>

int main(void)
{
	int failures,num;
	double grade,total;

	printf("enter grade:");
	scanf("%lf",&grade);

	failures=num=0;
	total=0;
	while(grade>=0)
	{
		total=total+grade;
		num++;
		if(grade<60)
			failures++;
		scanf("%lf",&grade);
	}
	
	if(num!=0)
		printf("grade average=%.2lf,failures=%d\n",total/num,failures);
	else
		printf("grade average=0,failures=0\n");

	return 0;
}