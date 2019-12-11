/* 大小写英文字母转换 */
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

	/*源代码2：
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