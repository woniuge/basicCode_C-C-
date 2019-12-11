/* 解密藏头诗（指针作为函数的返回值） */
#include <stdio.h>
char *change(char s[][20],char t[]);

int main(void)
{
	int i;
	char s[4][20],t[10],*p;

	printf("请输入藏头诗：\n");
	for(i=0;i<4;i++)
		scanf("%s",s[i]);

	p=change(s,t);

	printf("%s\n",p);

	return 0;
}

char *change(char s[][20],char t[])
{
	int i;

	for(i=0;i<4;i++)
	{
		t[2*i]=s[i][0];
		t[2*i+1]=s[i][1];
	}
	t[2*i]='\0';

	return t;
}