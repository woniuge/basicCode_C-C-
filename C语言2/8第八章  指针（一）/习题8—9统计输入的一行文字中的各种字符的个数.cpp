/* ͳ�������һ�������еĸ����ַ��ĸ��� */
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

	printf("��д��ĸ����Ϊ:%d\nСд��ĸ����Ϊ:%d\n�ո����Ϊ:%d\n���ָ���Ϊ:%d\n�����ַ�����Ϊ:%d\n",dx,xx,blank,digit,other);
}