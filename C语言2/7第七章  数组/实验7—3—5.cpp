/* ��ȥ�ַ��������еķ�ʮ�������ַ������һ�����ַ���
��ʮ��������ʽ����Ȼ����ת��Ϊʮ����������� */
#include <stdio.h>

int main(void)
{
	int i,k,n;
	char str[80];
	char h[80];

	printf("Input a string:");
	i=0;
	while((str[i]=getchar())!='\n')
		i++;
	str[i]='\0';

	k=0;
	for(i=0;str[i]!='\0';i++)
		if((str[i]>='A')&&(str[i]<='F')||(str[i]>='a')&&(str[i]<='f')||(str[i]>='0')&&(str[i]<='9'))
		{
			h[k]=str[i];
			k++;
		}
	h[k]='\0';

	n=0;
	for(k=0;h[k]!='\0';k++)
	{
		if((h[k]>='0')&&(h[k]<='9'))
			n=n*16+h[k]-'0';
		if((h[k]>='A')&&(h[k]<='F'))
			n=n*16+h[k]-'A'+10;
		if((h[k]>='a')&&(h[k]<='f'))
			n=n*16+h[k]-'a'+10;
	}

	printf("Hex=%d",n);
	printf("\n");

	return 0;
}
