/* 统计输入的一批字符（包括英文字母，数字字符和其他字符）中各类字符的数量 */
#include <stdio.h>

int main(void)
{
	int i,letter,digit,other;
	char ch;

	printf("enter 10 characters:");

	letter=digit=other=0;
	for(i=1;i<=10;i++)
	{
		ch=getchar();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			letter++;
		else if(ch>='0'&&ch<='9')
			digit++;
		else
			other++;
	}

	printf("letter=%d,digit=%d,other=%d\n",letter,digit,other);

	return 0;
}