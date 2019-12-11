/* 统计字符串中大写辅音字母的个数 */
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

	count=0;
	for(i=0;str[i]!='\0';i++)
		if((str[i]>'A')&&(str[i]<='Z')&&(str[i]!='E')&&(str[i]!='I')&&(str[i]!='O')&&(str[i]!='U'))
			count++;

	printf("count=%d\n",count);

	return 0;
}
