/* 将5个字符串按从小到大的顺序输出（用指针数组实现） */
#include <stdio.h>
#include <string.h>
void fsort(char *color[],int n);

int main(void)
{
	int i;
	char *pcolor[]={"red","blue","yellow","green","purple"};

	printf("%x\n",&"red");
	fsort(pcolor,5);

	int first=1;
	for(i=0;i<5;i++)
	{
		if(first)
			first=0;
		else
			printf(" ");
		printf("%s",pcolor[i]);
	}

	printf("\n");

	printf("%x\n",&"red");

	return 0;
}

void fsort(char *color[],int n)
{
	int i,j;
	char *temp;

	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(strcmp(color[j],color[j+1])>0)
			{
				temp=color[j];
				color[j]=color[j+1];
				color[j+1]=temp;
			}
}

	
