/* 用动态分配内存的方式输入多个字符串并排序 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 20
#define N 10
void fsort(char *ps[],int n);

int main(void)
{
	int i,n=0;
	char *pstr[M],str[N];
	
	do{
		printf("请输入字符串，每行一个，#结束输入：\n");
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
	
	fsort(pstr,n);

	printf("从小到大排序后为：");
	int first=1;
	for(i=0;i<n;i++)
	{
		if(first)
			first=0;
		else
			printf(" ");
		printf("%s",pstr[i]);
	}

	free(*pstr);

	printf("\n");

	return 0;
}

void fsort(char *ps[],int n)
{
	int i,j;
	char *temp;

	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(strcmp(ps[j],ps[j+1])>0)
			{
				temp=ps[j];
				ps[j]=ps[j+1];
				ps[j+1]=temp;
			}
}

	
