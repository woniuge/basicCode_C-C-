/* ͳ�������һ���ַ�������Ӣ����ĸ�������ַ��������ַ����и����ַ������� */
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