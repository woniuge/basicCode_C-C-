/*  ��nյ�ƣ����Ϊ1~n����һ���˰����еƴ򿪣��ڶ����˰�������
���Ϊ2�ı����Ŀ��أ���Щ�ƽ����ص������������˰������б��Ϊ3
�ı����Ŀ��أ����йص��ĵƽ����򿪣����ŵĵƽ����رգ���������
�ƣ�һ����k���ˣ����������Щ�ƿ��ţ����룺n��k��������ŵĵ�
��š�k<=n<=1000	�������룺7 3 ���������1 5 6 7  */
#include <stdio.h>

int main(void)
{
	int i,j,n,k,first;
	int a[1010];

	printf("enter n and k:");
	scanf("%d%d",&n,&k);

	for(i=1;i<=n;i++)
		a[i]=1;

	for(j=2;j<=k;j++)
		for(i=1;i<=n;i++)
			if(i%j==0)
				a[i]=-a[i];

	first=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			if(first)
				first=0;
			else
				printf(" ");

			printf("%d",i);
		}
	}

	printf("\n");

	return 0;
}