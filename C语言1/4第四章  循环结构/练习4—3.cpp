/* ����һ����ʵ��eps�����㲢�����ʽ��s=1-1/4+1/7-1/10+1/13-1/16+...����ֵ��ֱ�����һ��ľ���ֵС��eps */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,denominator,flag;
	double eps,item,sum;

	printf("eps(>0):");
	scanf("%lf",&eps);

	denominator=flag=1;
	item=1.0;
	sum=0;
	do{
		item=flag*1.0/denominator;
		sum=sum+item;
		flag=-flag;
		denominator=denominator+3;
		}while(fabs(item)>=eps);

	printf("sum=%.4lf\n",sum);

	return 0;
}