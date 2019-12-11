/* 输入行驶里程kilometers与等待时间wait，计算并输出乘车费用charge */
#include <stdio.h>

int main(void)
{
	int kilometers,wait,charge1,charge2,charge;
	
	printf("enter kilometers(>0):");
	scanf("%d",&kilometers);
	printf("enter wait(>0):");
	scanf("%d",&wait);

	if(kilometers<=3)
		charge1=10;
	else
		if(kilometers<=13)
			charge1=2*kilometers+4;
		else
			charge1=3*kilometers-9;
	
	charge2=wait/5*2;
	charge=charge1+charge2;
	
	printf("charge=%d\n",charge);

		return 0;
}