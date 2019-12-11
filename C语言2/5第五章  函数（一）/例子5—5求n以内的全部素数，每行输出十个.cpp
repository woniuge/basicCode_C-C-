/* ��n���ڵ�ȫ��������ÿ�����ʮ����Ҫ����͵��ú���prime��m��
�ж�m�Ƿ�Ϊ��������mΪ����ʱ����1�����򷵻�0. */
#include <stdio.h>
#include <math.h>
int prime(int m);

int main(void)
{
	int i,n,count=0;

	printf("enter n:");
	scanf("%d",&n);

	for(i=2;i<=n;i++)
		if(prime(i))
		{
			printf("%4d",i);
			count++;
			if(count%10==0)
				printf("\n");
		}

	printf("\n");

	return 0;
}

int prime(int m)
{
	int i;

	if(m<=1)
		return 0;
	else
		for(i=2;i<=sqrt(m);i++)
		if(m%i==0)
			return 0;

	return 1;
}
