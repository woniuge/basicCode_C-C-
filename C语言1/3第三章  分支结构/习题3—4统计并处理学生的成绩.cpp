/* 输入一批学生的成绩，计算平均分，并统计各等级成绩的个数 */
#include <stdio.h>

int main(void)
{
	int i,n,A,B,C,D,E;
	double grade,total;

	printf("enter n:");
	scanf("%d",&n);

	total=A=B=C=D=E=0;
	for(i=1;i<=n;i++)
	{
		printf("enter grade(0<=grade<=100) #%d:",i);
		scanf("%lf",&grade);

		total=total+grade;

		if(grade>=0&&grade<=59)
			E++;
		else
			if(grade>=60&&grade<=69)
				D++;
			else
				if(grade>=70&&grade<=79)
					C++;
				else
					if(grade>=80&&grade<=89)
						B++;
					else
						if(grade>=90&&grade<=100)
							A++;
	}

	printf("grade average=%.2f\n",total/n);
	printf("A(90~100)=%d,B(80~89)=%d,C(70~79)=%d,D(60~69)=%d,E(0~59)=%d.\n",A,B,C,D,E);

	return 0;
}