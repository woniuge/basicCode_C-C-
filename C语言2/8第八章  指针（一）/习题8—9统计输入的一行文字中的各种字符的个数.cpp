/* 统计输入的一行文字中的各种字符的个数 */
#include <stdio.h>
void tongji(char s[]);

int main(void)
{
	char s[256];

	printf("Input a string:");
	gets(s);

	tongji(s);

	return 0;
}

void tongji(char s[])
{
	char *p;
	int dx=0,xx=0,blank=0,digit=0,other=0;
	
	p=s;
	for(;*p!='\0';p++)
		if(*p>='A'&&*p<='Z')
			dx++;
		else
			if(*p>='a'&&*p<='z')
				xx++;
			else
				if(*p==' ')
					blank++;
				else
					if(*p>='0'&&*p<='9')
						digit++;
					else
						other++;

	printf("大写字母个数为:%d\n小写字母个数为:%d\n空格个数为:%d\n数字个数为:%d\n其他字符个数为:%d\n",dx,xx,blank,digit,other);
}