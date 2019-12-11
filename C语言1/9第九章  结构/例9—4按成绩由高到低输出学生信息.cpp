/* 按成绩由高到低输出学生信息 */
#include <stdio.h>
struct student
{
	int num;
	char name[20];
	int score;
};
struct student stud[10];

int main(void)
{
	int i,j,index,sum=0;
	struct student temp;

	printf("Input the student's number,name and score:\n");
	for(i=0;i<10;i++)
	{
		printf("No %d:",i+1);
		scanf("%d%s%d",&stud[i].num,stud[i].name,&stud[i].score);
		sum+=stud[i].score;
	}

	for(i=0;i<9;i++)
	{
		index=i;
		for(j=i+1;j<10;j++)
			if(stud[j].score<stud[index].score)
				index=j;
		temp=stud[index];
		stud[index]=stud[i];
		stud[i]=temp;
	}

	printf("The average:%d\n",sum/10);
	printf("The student score:\n");
	for(i=0;i<10;i++)
		printf("%d %s %d\n",stud[i].num,stud[i].name,stud[i].score);

	return 0;
}