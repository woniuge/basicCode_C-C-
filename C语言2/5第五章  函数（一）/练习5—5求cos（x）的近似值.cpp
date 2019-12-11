/* 输入精度e，用下列公式求cos（x）的近似值，精确到最后一项的绝对值小于e。
要求定义和调用函数funcos（e，x）求余弦函数的近似值。
cos（x）=x^0/0!-x^2/2!+x^4/4!-x^6/6!+... */
#include <stdio.h>
#include <math.h>
double funcos(double e,double x);
double fact(int m);

int main(void)
{
	double e,x,cos;

	printf("enter e and x:");
	scanf("%lf%lf",&e,&x);

	cos=funcos(e,x);

	printf("cos(%lf)=%lf\n",x,cos);

	return 0;
}

double funcos(double e,double x)
{
	int flag,i;
	double item,funcos;

	i=0;
	flag=1;
	item=1.0;
	funcos=0.0;
	while(fabs(item)>=e)
	{
		item=flag*pow(x,i)/fact(i);
		funcos=funcos+item;
		flag=-flag;
		i=i+2;
	}

	return funcos;
}

double fact(int m)
{
	int i;
	double result;

	result=1;
	for(i=1;i<=m;i++)
		result=result*i;

	return result;
}