/* ×Ö·û´®ÖÐ´óÐ´×ÖÄ¸»¥ÏàÌæ»» */
#include <stdio.h>

int main(void)
{
	int i;
	char str[80];

	printf("Input a string:");
	i=0;
	while((str[i]=getchar())!='\n')
		i++;
	str[i]='\0';

	for(i=0;str[i]!='\0';i++)
		if((str[i]>='A')&&(str[i]<='Z'))
			str[i]='A'+'Z'-str[i];

	for(i=0;str[i]!='\0';i++)
		putchar(str[i]);

	printf("\n");

	return 0;
}
