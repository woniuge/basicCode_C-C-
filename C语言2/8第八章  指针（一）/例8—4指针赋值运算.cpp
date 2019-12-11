/* 指针赋值运算 */
#include <stdio.h>

int main(void)
{
	int a,b,c,*p1,*p2;

	a=2;b=4;c=6;
	p1=&a,p2=&b;		/* p1指向a,p2指向b */
	printf("a=%d,b=%d,c=%d,*p1=%d,*p2=%d\n",a,b,c,*p1,*p2);

	p2=p1;p1=&c;		/* 改变指针p1和p2的值 */
	printf("a=%d,b=%d,c=%d,*p1=%d,*p2=%d\n",a,b,c,*p1,*p2);

	return 0;
}