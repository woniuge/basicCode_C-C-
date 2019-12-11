/* 输入精度e，使用格里高利公式求pi的近似值，精确到最后一项的绝对值小于
e。要求定义和调用函数funpi(e)求pi的近似值。pi/4=1-1/3+1/5-1/7+... */
#include <stdio.h>
#include <math.h>
double funpi(double e);
int digits(double e);

int main(void)
{
	double e,pi;
	int m;

	printf("enter e:");
	scanf("%lf",&e);

	pi=funpi(e);
	m=digits(e);

	switch(m)
	{
		case 1:
			printf("pi=%.1f\n",pi);
			break;
		case 2:
			printf("pi=%.2f\n",pi);
			break;
		case 3:
			printf("pi=%.3f\n",pi);
			break;
		case 4:
			printf("pi=%.4f\n",pi);
			break;
		case 5:
			printf("pi=%.5f\n",pi);
			break;
		case 6:
			printf("pi=%.6f\n",pi);
			break;
	}

	return 0;
}

double funpi(double e)
{
	int flag,denominator;
	double item,sum;

	flag=denominator=1;
	item=1.0;
	sum=0.0;
	while(fabs(item)>=e)
	{
		item=flag*1.0/denominator;
		sum=sum+item;
		flag=-flag;
		denominator=denominator+2;
	}

	return sum*4;
}

int digits(double e)
{
	int count=0;

	do{
		e=e*10;
		count++;
	  }while(e<1);

	return count;
}