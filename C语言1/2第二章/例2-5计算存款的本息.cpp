#include <stdio.h>
#include <math.h>

int main(void)
{
	int money,year;
	double rate,sum;			

	printf("enter money:");
	scanf("%d",&money);
	printf("enter year:");
	scanf("%d",&year);
	printf("enter rate:");
	scanf("%lf",&rate);

													/*  ��һ�ּ�д��������������ݼ�Ҫ�ӿո�
														printf("enter money:\n");
														printf("enter year:\n");
														printf("enter rate:\n");
														scanf("%d%d%lf",&money,&year,&rate);   */

													/*  �ڶ��ּ�д��������������ݼ�Ҫ�ӿո�
														printf("enter money:\n enter year:\n enter rate:\n");			
														scanf("%d%d%lf",&money,&year,&rate);	*/			

	sum=money*pow((1+rate),year);
	printf("sum=%.2f\n",sum);
												
	return 0;
}