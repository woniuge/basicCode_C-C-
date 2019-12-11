/* √‹¬Î±‰ªªŒ Ã‚ */
#include <stdio.h>
#include <string.h>
#define MAXLINE 100
void encrypt (char *);

int main(void)
{
	char line [MAXLINE];

	printf("Input the string:");
	gets(line);
	encrypt(line);
	printf("After been encrypted:%s\n",line);

	return 0;
}

void encrypt (char *s)
{
	for(;*s!='\0';s++)
		if(*s=='z')
			*s='a';
		else
			*s=*s+1;
}