/* ���ַ�����ǰ������ĸ�Ƶ�������磬
���롰abcdef���������defabc�� */
#include <stdio.h>
#include <string.h>
#define MAXLINE 100
void move(char s[]);

int main(void)
{
	char line[MAXLINE];

	printf("Input the string:");
	gets(line);
	if(strlen(line)<3)
		printf("NO!\n");
	else
	{
		move(line);
		printf("After been moved:%s\n",line);
	}

	return 0;
}

void move(char s[])
{
	int i;
	char t1[MAXLINE],t2[MAXLINE];

	for(i=0;i<3;i++)
		t1[i]=s[i];
	t1[i]='\0';
	for(i=3;s[i]!='\0';i++)
		t2[i-3]=s[i];
	t2[i-3]='\0';
	strcat(t2,t1);
	strcpy(s,t2);
}