/* n����Χ��һȦ����3�����˳�Ȧ�� �����������˵ı��
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

	while(n>1)
	{
		for(i=0;i<t;i++)
		{
			if(*(p+i)==1)
			{
				sum++;
				if(sum%3==0)
				{
					*(p+i)=0;
					n--;
				}
			}
		}
	}

	for(i=0;i<t;i++)
		if(*(p+i)==1)
			printf("Last No.is:%d\n",i+1);

	free(p);

	return 0;
}