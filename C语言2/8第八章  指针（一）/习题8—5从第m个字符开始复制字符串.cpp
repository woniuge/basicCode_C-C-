/* 从第m个字符开始复制字符串 */
#include <stdio.h>
#include <string.h>
#define MAXLINE 100
void mcopy(char *s,int m);

int main(void)
{
	char line[MAXLINE];
	char *s;
	int m;

	s=line;
	printf("Input the string:");
	gets(line);
	do
	{
		printf("Input m:");
		scanf("%d",&m);
	}while(m>(int)strlen(line));
	
	mcopy(s,m);
	printf("After been copied:%s\n",s);

	return 0;
}

void mcopy(char *s,int m)
{
	char *pt;

	pt=s+m-1;
	strcpy(s,pt);
}

/* 用两个指针实现*/
#include <stdio.h>
#include <string.h>
#define MAXLINE 100
char * mcopy(char *s,int m);

int main(void)
{
	char line[MAXLINE];
	char *s,*n_s;
	int m;

	s=line;
	printf("Input the string:");
	gets(line);
	do
	{
		printf("Input m:");
		scanf("%d",&m);
	}while(m>(int)strlen(line));
	
	n_s=mcopy(s,m);
	printf("After been copied:%s\n",n_s);

	return 0;
}

char * mcopy(char *s,int m)
{
	char *pt;

	pt=s+m-1;
	
	return pt;
}
