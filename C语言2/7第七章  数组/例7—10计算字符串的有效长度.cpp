/* 计算字符串的有效长度 */
#include<stdio.h>

int main(void)
{
	int i=0,len;
	char str[80]="Happy";

	for(i=0;str[i]!='\0';i++);

	len=i;
	printf("len=%d\n",len);

	for(i=0;str[i]!='\0';i++)
		putchar(str[i]);

	printf("\n");

	return 0;
}