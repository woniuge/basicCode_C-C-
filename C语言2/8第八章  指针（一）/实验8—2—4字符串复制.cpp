#include <stdio.h>
#include <string.h>
#define MAXLINE 100
char * strmcpy(char s[],char t[],int m);

int main(void)
{
	char t[MAXLINE];
	char s[MAXLINE];
	char *pt,*ps;
	int m;

	pt=t;
	ps=s;
	printf("Input the string:");
	gets(t);
	do
	{
		printf("Input m:");
		scanf("%d",&m);
	}while(m>(int)strlen(t));
	
	ps=strmcpy(s,t,m);
	printf("After been copied:%s\n",ps);

	return 0;
}

char * strmcpy(char s[],char t[],int m)
{
	char *pt,*ps;

	pt=t;
	ps=pt+m-1;
	
	return ps;
}
