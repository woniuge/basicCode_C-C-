/* 指针变量初始化 */
#include <stdio.h>

int main(void)
{
	int a=1,b=2;
	int *p1=&a,*p2=&b,*pt;			/* 在定义指针p1和p2的同时对其赋值 */

	printf("a=%d,b=%d,*p1=%d,*p2=%d\n",a,b,*p1,*p2);

	pt=p1;
	p1=p2;			/* 交换p1和p2的值 */
	p2=pt;
	printf("a=%d,b=%d,*p1=%d,*p2=%d\n",a,b,*p1,*p2);

	return 0;
}