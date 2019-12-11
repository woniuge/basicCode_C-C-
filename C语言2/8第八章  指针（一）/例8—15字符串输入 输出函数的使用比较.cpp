/* 程序A：使用scanf（）和printf（）
函数输入/输出字符串的示例 */
#include <stdio.h>

int main(void)
{
	char str[80];

	scanf("%s",str);
	printf("%s",str);
	printf("%s","Hello");

	printf("\n");

	return 0;
}

/* 程序B：使用gets（）和puts（）
函数输入/输出字符串的示例 */
#include <stdio.h>

int main(void)
{
	char str[80];

	gets(str);
	puts(str);
	puts("Hello");

	return 0;
}