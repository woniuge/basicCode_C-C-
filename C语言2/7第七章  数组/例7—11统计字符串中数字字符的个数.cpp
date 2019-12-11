/* 统计字符串中数字字符的个数 */
#include <stdio.h>

int main(void)
{
	int i,count;
	char str[80];

	printf("Enter a string:");

	i=0;
	while((str[i]=getchar())!='\n')
		i++;
	str[i]='\0';

	count=0;
	for(i=0;str[i]!='\0';i++)
		if(str[i]>='0'&&str[i]<='9')
			count++;
	printf("count=%d\n",count);

	return 0;
}