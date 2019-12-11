/* 统计一行字符中单词的个数 */
#include <stdio.h>

int main(void)
{
	int count=0;
	char ch;

	printf("Input words:");

	while((ch=getchar())!='\n')
		while(ch==' ')
		{
			count++;
			break;
		}

	printf("count=%d\n",count+1);

	return 0;
}