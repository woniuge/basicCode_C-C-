/* 使用指针改变所指向变量的值 */
#include <stdio.h>

int main(void)
{
	int a=1,b=2,t;
	int *p1,*p2;

	p1=&a;
	p2=&b;
	printf("a=%d,b=%d,*p1=%d,*p2=%d\n",a,b,*p1,*p2);

	t=*p1;
	*p1=*p2;			/* 交换*p1和*p2的值 */
	*p2=t;
	printf("a=%d,b=%d,*p1=%d,*p2=%d\n",a,b,*p1,*p2);

	return 0;
}