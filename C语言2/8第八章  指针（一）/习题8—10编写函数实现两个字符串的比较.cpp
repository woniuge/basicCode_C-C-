/* 编写函数strcomp（s1,s2），实现两个字符串的比较 */
#include <stdio.h>
int strcomp(char s1[],char s2[]);

int main(void)
{
	int t;
	char s1[20],s2[20];

	printf("Input the first string:");
	gets(s1);
	printf("Input the second string:");
	gets(s2);

	t=strcomp(s1,s2);

	if(t==1)
		printf("s1>s2\n");
	else
		if(t==0)
			printf("s1=s2\n");
		else
			printf("s1<s2\n");

	return 0;
}

int strcomp(char s1[],char s2[])
{
	char *p1,*p2;

	for(p1=s1,p2=s2;*p1!='\0'&&*p2!='\0';p1++,p2++)
	{
		if(*p1>*p2)
		{
			return 1;
			break;
		}
		else
			if(*p1<*p2)
			{
				return -1;
				break;
			}
	}
	if(*p1=='\0'&&*p2=='\0')
		return 0;
}