/* ����һ��������n�����2/1+3/2+5/3+8/5+...��ǰn��֮�ͣ�
������λС�����������дӵ�2����ÿһ��ķ�����ǰһ���
�����ĸ�ĺͣ���ĸdenominator��ǰһ��ķ���numerator�� */
#include <stdio.h>

int main(void)
{
	int i,n;
	double numerator,denominator,item,sum;

	printf("enter n:");
	scanf("%d",&n);

	numerator=2;
	denominator=1;
	sum=0;
	for(i=1;i<=n;i++)
	{
		item=numerator/denominator;
		sum=sum+item;
		numerator=numerator+denominator;
		denominator=numerator-denominator;
	}

	printf("sum=%.2lf\n",sum);

	return 0;
}
