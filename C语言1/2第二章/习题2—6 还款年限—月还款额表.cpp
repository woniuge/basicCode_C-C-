/* ��������loan��������rate��������������ޡ��»����� */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,month;
	double loan,rate,money;

	printf("enter loan:");
	scanf("%lf",&loan);
	printf("enter rate:");
	scanf("%lf",&rate);

	for(i=5;i<=30;i++)
	{
		month=12*i;
		money=loan*rate*pow((1+rate),month)	/(pow((1+rate),month)-1);
		printf("%d-%.0f\n",i,money);
	}

	return 0;
}