/* 将字符串中所有的ch字符删除后输出该字符串 */
#include <stdio.h>
#define MAXLINE 256
void delchar(char s[],char c);

int main(void)
{
	char line[MAXLINE];
	char ch;

	printf("Input a string:");
	gets(line);
	printf("Input a character:");
	ch=getchar();

	delchar(line,ch);

	printf("\n");

	return 0;
}

void delchar(char s[],char c)
{
	char *p;
	
	p=s;
	for(;*p!='\0';p++)
		if(*p!=c)
			putchar(*p);
}
