/* ����һ��ʵ��x�����㲢�����ʽ��s=x+x^2/2!+x^3/3!+x^4/4!+...����
ֵ��ֱ�����һ��ľ���ֵС��10^(-5)(������λС��)��Ҫ����͵��ú�
��fact��n��������n�Ľ׳ˣ����Ե���pow�����������ݡ� */
#include <stdio.h>
#include <math.h>
double fact(int n);

int main(void)
{
	int i;
	double x,item,s;

	printf("enter x:");
	scanf("%lf",&x);

	i=1;
	s=0;
	
	  do{
			item=pow(x,i)/fact(i);
			s=s+item;
			i++;
		}while(fabs(item>0.00001));

	  printf("s=%.2lf\n",s);

	  return 0;
} 

double fact(int n)
{
	int i;
	double result;

	result=1.0;
	for(i=1;i<=n;i++)
		result=result*i;

	return result;
}

