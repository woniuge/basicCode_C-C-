/* �����ַ����е��ַ�λ�� */
#include <stdio.h>
char *match(char *s,char ch)
{
	while(*s!='\0')
		if(*s==ch)
			return s;
		else
			s++;
		return NULL;
}

int main(void)
{
	char ch,str[80],*p=NULL;

	printf("Please input the string:\n");
	scanf("%s",str);
	getchar();
	ch=getchar();
	if((p=match(str,ch))!=NULL)
		printf("%s\n",p);
	else
		printf("Not Found\n");

	return 0;
}