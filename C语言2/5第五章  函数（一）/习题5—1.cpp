/* ��������������a��n����a+aa+aaa+...+aa...a��n��a��֮�͡�
Ҫ���岢���ú���fn��a��n�������Ĺ����Ƿ���aa...a��n��a����
���磬fn��3,2���ķ���ֵ��33�� */
#include <stdio.h>
double fn(int a,int n);

int main(void)
{
	int i,a,n;
	double sum;

	printf("enter a and n:");
	scanf("%d%d",&a,&n);

	sum=0.0;
	for(i=1;i<=n;i++)
		sum=sum+fn(a,i);

	printf("sum=%.0lf\n",sum);

	return 0;
}

double fn(int a,int n)
{
	int i;
	double item;

	item=0;
	for(i=1;i<=n;i++)
		item=item*10+a;

	return item;
}