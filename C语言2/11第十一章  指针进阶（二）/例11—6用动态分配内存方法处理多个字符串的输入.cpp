/* �ö�̬�����ڴ淽���������ַ��������� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i,n=0;
	char *color[20],str[10];

	do
	{
		printf("��������ɫ���ƣ�ÿ��һ����#�������룺\n");
		scanf("%s",str);
	}while(str[0]=='#');
	while(str[0]!='#')
	{
		if((color[n]=(char *)malloc(sizeof(char)*(strlen(str)+1)))==NULL)
		{
			printf("Not able to allocate memory.\n");
			exit(1);
		}
		strcpy(color[n],str);
		n++;
		scanf("%s",str);
	}
	
	printf("���������ɫ�ǣ�");
	int first=1;
	for(i=0;i<n;i++)
	{
		if(first)
			first=0;
		else
			printf(" ");
		printf("%s",color[i]);
	}

	free(*color);

	printf("\n");

	return 0;
}