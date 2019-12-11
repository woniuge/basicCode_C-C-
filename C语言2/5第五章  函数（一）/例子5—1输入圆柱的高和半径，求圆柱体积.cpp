/* 输入圆柱cylinder的高和半径，求圆柱体积,volume=pi*r^2*h。
要求定义和调用函数cylinder（r，h）计算圆柱体的体积。 */
#include <stdio.h>
double cylinder(double r,double h);

int main(void)
{
	double height,radius,volume;

	printf("enter radius and height:");
	scanf("%lf%lf",&radius,&height);

	volume=cylinder(radius,height);		/* 调用函数，返回值赋给volume */

	printf("volume=%.3lf\n",volume);

	return 0;
}

double cylinder(double r,double h)
{
	double result;

	result=3.1415926*r*r*h;

	return result;
}