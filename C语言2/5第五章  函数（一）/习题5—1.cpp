/* 输入两个正整数a和n，求a+aa+aaa+...+aa...a（n个a）之和。
要求定义并调用函数fn（a，n），它的功能是返回aa...a（n个a）。
例如，fn（3,2）的返回值是33。 */
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