/* ʹ��Ƕ��ѭ����n���ڵ�ȫ������ */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,m,n,count;

	printf("enter n:");
	scanf("%d",&n);

	count=0;
	for(m=2;m<=n;m++)
	{
		for(i=2;i<=sqrt(m);i++)
			if(m%i==0)break;
		if(i>sqrt(m))
		{
			printf("%6d",m);
			count++;
			if(count%10==0)
				printf("\n");
		}
	}

	printf("\n");

	return 0;
}