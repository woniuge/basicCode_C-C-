/* ��ȥ�ַ��������еķ������ַ������һ������ */
#include<stdio.h>

int main(void)
{
	int i,n;
	char str[80];

	printf("Input a string:");
	i=0;
	while((str[i]=getchar())!='\n')
		i++;
	str[i]='\0';

	n=0;
	for(i=0;str[i]!='\0';i++)
		if((str[i]>='0')&&(str[i]<='9'))
			n=n*10+str[i]-'0';
	
	printf("%d\n",n);

	return 0;
}
