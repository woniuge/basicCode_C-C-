/* ����һ�����������������Ϊ������־���������е������͡�Ҫ����
�͵��ú���even��n���ж�������ż�ԣ���nΪż��ʱ����1�����򷵻�0. */
#include <stdio.h>
int even(int n);

int main(void)
{
	int n,sum=0;

	printf("enter digits:");
	scanf("%d",&n);

	if(n<=0)
		printf("No!\n");
	else
	{
		while(n>0)
		{
			if(even(n)==0)
				sum=sum+n;
			scanf("%d",&n);
		}

		printf("the sum of odd is %d.\n",sum);
	}

	return 0;
}

int even(int n)
{
	if(n%2==0)
		return 1;
	else
		return 0;
}
