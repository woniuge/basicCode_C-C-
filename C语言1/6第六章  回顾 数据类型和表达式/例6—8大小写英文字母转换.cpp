/* ��СдӢ����ĸת�� */
#include <stdio.h>

int main(void)
{
	char ch;

	printf("input character:");

	ch=getchar();
	while(ch!='\n')
	{
		if(ch>='A'&&ch<='Z')
			ch=ch-'A'+'a';
		else if(ch>='a'&&ch<='z')
			ch=ch-'a'+'A';
		putchar(ch);
		ch=getchar();
	}

	/*Դ����2��
	while((ch=getchar())!='\n')
	{
			if(ch>='A'&&ch<='Z')
			ch=ch-'A'+'a';
		else if(ch>='a'&&ch<='z')
			ch=ch-'a'+'A';
		putchar(ch);	
	}		*/

	putchar('\n');

	return 0;
}