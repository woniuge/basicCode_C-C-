/* ����A��ʹ��scanf������printf����
��������/����ַ�����ʾ�� */
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

/* ����B��ʹ��gets������puts����
��������/����ַ�����ʾ�� */
#include <stdio.h>

int main(void)
{
	char str[80];

	gets(str);
	puts(str);
	puts("Hello");

	return 0;
}