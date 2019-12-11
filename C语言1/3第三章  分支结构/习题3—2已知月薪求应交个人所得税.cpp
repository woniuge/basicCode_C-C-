/* 已知月薪salary求应交个人所得税tax */
#include <stdio.h>

int main(void)
{
	int rate;
	double salary,tax;
	
	printf("enter salary:");
	scanf("%lf",&salary);

	if(salary<=850)
		rate=0;
	else
		if(salary<=1350)
			rate=5;
		else
			if(salary<=2850)
				rate=10;
			else
				if(salary<=5850)
					rate=15;
				else
					rate=20;
	tax=rate*(salary-850)/100;

	printf("tax=%.2f\n",tax);

	return 0;
}