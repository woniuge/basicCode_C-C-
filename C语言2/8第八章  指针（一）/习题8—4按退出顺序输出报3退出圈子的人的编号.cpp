/* ���˳�˳�������3�˳�Ȧ�ӵ��˵ı��,
0������Ȧ���У�1������Ȧ����  Լɪ������ */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i,n,sum=0,t;
	int *p;
	
	printf("Input n:");
	scanf("%d",&n);
	t=n;
	if((p=(int *)calloc(n,sizeof(int)))==NULL)
	{
		printf("Not able to allocate memory.\n");
		exit(1);
	}
	for(i=0;i<n;i++)
		*(p+i)=1;

	int first=1;
	while(n>1)
	{
		for(i=0;i<t;i++)
		{
			if(*(p+i)==1)
			{
				sum++;
				if(sum%3==0)
				{
					if(first)
						first=0;
					else
						printf(" ");
					printf("%d",i+1);
					*(p+i)=0;
					n--;
				}
			}
		}
	}
	free(p);

	printf("\n");

	return 0;
}