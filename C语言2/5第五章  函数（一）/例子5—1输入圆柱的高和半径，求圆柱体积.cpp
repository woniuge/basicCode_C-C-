/* ����Բ��cylinder�ĸߺͰ뾶����Բ�����,volume=pi*r^2*h��
Ҫ����͵��ú���cylinder��r��h������Բ���������� */
#include <stdio.h>
double cylinder(double r,double h);

int main(void)
{
	double height,radius,volume;

	printf("enter radius and height:");
	scanf("%lf%lf",&radius,&height);

	volume=cylinder(radius,height);		/* ���ú���������ֵ����volume */

	printf("volume=%.3lf\n",volume);

	return 0;
}

double cylinder(double r,double h)
{
	double result;

	result=3.1415926*r*r*h;

	return result;
}