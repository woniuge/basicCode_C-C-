/* 使用格里高利公式求π的近似值，要求精确到最后一项的绝对值小于10^-4 */
#include <stdio.h>
#include <math.h>						/* 程序中调用绝对值函数fabs(),需包含math.h */

int main(void)
{
	int denominator,flag;
	double item,pi;						/* pi用于存放累加和 */

	flag=denominator=1;					/* flag(denominator)表示第i项的符号(分母)，初始为正(1) */
	item=1.0;							/* item中存放第i项的值，初值取1 */
	pi=0;								/* 置累加和pi的初值为0 */

	while(fabs(item)>=0.0001)
	{
		item=flag*1.0/denominator;
		pi=pi+item;
		flag=-flag;
		denominator=denominator+2;
	}

	pi=pi*4;							/* 循环计算的结果是pi/4 */
	printf("pi=%.4f\n",pi);

	return 0;
}