/* �ö�̬�����ڴ�ķ�ʽ�������ַ�����z�ҳ���� */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20
#define N 10
char * fmax(char *ps[],int n);

int main(void)
{
	int n=0;
	char *pstr[M],str[N];
	char *max;
	
	do{
		printf("�������ַ�����ÿ��һ����#�������룺\n");
		scanf("%s",str);
	  }while(str[0]=='#');
	while(str[0]!='#')
	{
		if((pstr[n]=(char *)malloc(sizeof(char)*(strlen(str)+1)))==NULL)
		{
			printf("Not able to allocate memory.\n");
			exit(1);
		}
		strcpy(pstr[n],str);
		n++;
		scanf("%s",str);
	}
	
	max=fmax(pstr,n);

	printf("����ַ���Ϊ��%s",max);

	free(*pstr);

	printf("\n");

	return 0;
}

char * fmax(char *ps[],int n)
{
	int j;
	char *temp;

	temp=ps[0];
	for(j=0;j<n;j++)
		if(strlen(ps[j])<strlen(ps[j+1]))
			temp=ps[j+1];

	return temp;
}

	
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char sx[80],smin[80];

	scanf("%s",sx);
	strcpy(smin,sx);
	for(i=1;i<5;i++)
	{
		scanf("%s",sx);
		if(strcmp(sx,smin)<0)
			strcpy(smin,sx);
	}

	printf("min is %s\n",smin);

	return 0;
}