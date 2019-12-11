/* 输入一个正整数n，输出2/1+3/2+5/3+8/5+...的前n项之和，
保留两位小数。（该序列从第2项起，每一项的分子是前一项分
子与分母的和，分母denominator是前一项的分子numerator） */
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
