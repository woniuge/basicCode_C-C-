/* 设置学生成绩等级并统计不及格人数（使用结构指针作为函数参数） */
#include <stdio.h>
#define N 10
struct student
{
	int num;
	char name[20];
	int score;
	char grade;
};
int set_grade(struct student *p,int n);

int main(void)
{
	struct student stu[N],*ptr;
	int i,count;

	ptr=stu;
	printf("Input the student's num,name and score:\n");
	for(i=0;i<N;i++)
	{
		printf("No %d:",i+1);
		scanf("%d%s%d",&stu[i].num,stu[i].name,&stu[i].score);
	}

	count=set_grade(ptr,N);

	printf("The count(<60):%d\n",count);
	printf("The student grade:\n");
	for(i=0;i<N;i++)
		printf("%d %s %c\n",stu[i].num,stu[i].name,stu[i].grade);

	return 0;
}

int set_grade(struct student *p,int n)
{
	int i,sum=0;

	for(i=0;i<n;i++,p++)
	{
		if(p->score>=85)
			p->grade='A';
		else if(p->score>=70)
			p->grade='B';
		else if(p->score>=60)
			p->grade='C';
		else
		{
			p->grade='D';
			sum++;
		}
	}

	return sum;
}