/* ��֤��°ͺղ��룺�κ�һ������6��ż�����ɱ�ʾΪ��������֮�͡�
����6=3+3.8=3+5,...,18=7+11.Ҫ��6~100֮���ż������ʾ��������
��֮�ͣ���ӡʱһ�д�ӡ���顣 */
#include <stdio.h>
#include <math.h>
int prime(int n);

int main(void)
{
	int i,n,a,b,count;

	printf("enter n:");
	scanf("%d",&n);

	count=0;
	for(i=6;i<=n;i=i+2)
		for(a=3;a<=n/2;a++)
		{
			b=i-a;
			if(i==prime(a)+prime(b))
			{
				printf("%3d=%2d+%2d",i,a,b);
				count++;
				if(count%5==0)
					printf("\n");
				break;
			}
		}

	printf("\n");

	return 0;
}

int prime(int n)
{
	int i,prime;

	if(n<=1);
	else
		{
			for(i=2;i<=sqrt(n);i++)
				if(n%i==0)
					break;
			if(i>sqrt(n))
				prime=n;
		}

	return prime;
}