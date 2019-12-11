/* 判断输入的一串字符是否为回文 */
#include <stdio.h>
#include <string.h>
int huiwen(char a[]);

int main(void)
{
	char s[256];

	printf("Input a string:");
	gets(s);
	if(huiwen(s))
		printf("YES\n");
	else
		printf("NO\n");

	return 0;
}

int huiwen(char a[])
{
	char *fp,*lp;
	int n;

	fp=a;
	n=strlen(fp);
	for(lp=fp+n-1;fp<lp;fp++,lp--)
		if(*fp!=*lp)
			return 0;
	return 1;
}