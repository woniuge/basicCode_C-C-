/* ʹ�ø��������ʽ��еĽ���ֵ��Ҫ��ȷ�����һ��ľ���ֵС��10^-4 */
#include <stdio.h>
#include <math.h>						/* �����е��þ���ֵ����fabs(),�����math.h */

int main(void)
{
	int denominator,flag;
	double item,pi;						/* pi���ڴ���ۼӺ� */

	flag=denominator=1;					/* flag(denominator)��ʾ��i��ķ���(��ĸ)����ʼΪ��(1) */
	item=1.0;							/* item�д�ŵ�i���ֵ����ֵȡ1 */
	pi=0;								/* ���ۼӺ�pi�ĳ�ֵΪ0 */

	while(fabs(item)>=0.0001)
	{
		item=flag*1.0/denominator;
		pi=pi+item;
		flag=-flag;
		denominator=denominator+2;
	}

	pi=pi*4;							/* ѭ������Ľ����pi/4 */
	printf("pi=%.4f\n",pi);

	return 0;
}