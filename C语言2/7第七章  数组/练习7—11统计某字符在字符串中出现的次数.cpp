/* 统计某字符在字符串中出现的次数 */
#include <stdio.h>

int main(void)
{
	int i,count;
	char str[80];
	char ch;

	printf("Input a string:");
	i=0;
	while((str[i]=getchar())!='\n')
		i++;
	str[i]='\0';

	printf("Input a character:");
	scanf("%c",&ch);

	count=0;
	for(i=0;str[i]!='\0';i++)
		if(str[i]==ch)
			count++;

	printf("count=%d\n",count);

	for(i=0;str[i]!='\0';i++)
		putchar(str[i]);

	printf("\n");
	return 0;
}
