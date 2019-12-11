/* 使用指针计算数组元素个数和数组元素的存储单元 */
#include <stdio.h>

int main(void)
{
	double a[2],*p,*q;

	p=&a[0];
	q=p+1;
	printf("%d\n",q-p);
	printf("%d\n",(int)q-(int)p);
	
	return 0;
}