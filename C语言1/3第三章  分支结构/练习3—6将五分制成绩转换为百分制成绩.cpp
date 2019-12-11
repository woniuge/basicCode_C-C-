/* 将五分制成绩转换为百分制成绩 */
#include <stdio.h>

int main(void)
{
	int i;
	char grade,ch;

	for(i=1;i<=6;i++)
	{
		printf("enter your grade:");
		scanf("%c",&grade);
		ch=getchar();

		switch(grade)
		{
		case'A':printf("90~100\n");break;
		case'B':printf("80~89\n");break;
		case'C':printf("70~79\n");break;
		case'D':printf("60~69\n");break;
		case'E':printf("0~59\n");break;
		default:printf("unknown grade\n");break;
		}
	}

	printf("thanks\n");

	return 0;
}