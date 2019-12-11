/* 输入一个实数x，计算并输出下式（s=x+x^2/2!+x^3/3!+x^4/4!+...）的
值，直到最后一项的绝对值小于10^(-5)(保留两位小数)。要求定义和调用函
数fact（n），计算n的阶乘，可以调用pow（）函数求幂。 */
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

