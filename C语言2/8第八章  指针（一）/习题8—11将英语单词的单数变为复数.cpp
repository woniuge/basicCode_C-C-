/* 将英语单词的单数变为复数 */
#include <stdio.h>
#include <string.h>
int jiewei(char s[]);

int main(void)
{
	int t;
	char s[20];

	printf("Input a word:");
	gets(s);

	t=jiewei(s);
	if(t)
		printf("%ses\n",s);
	else
		printf("%ss\n",s);

	return 0;
}

int jiewei(char a[])
{
	int n;
	char *p;

	p=a;
	n=strlen(p);
	if(*(p+n-1)=='y'||*(p+n-1)=='s'||*(p+n-1)=='x'||*(p+n-1)=='o'||*(p+n-1)=='h'&&(*(p+n-2)=='c'||*(p+n-2)=='s'))
		return 1;
	else
		return 0;
}
