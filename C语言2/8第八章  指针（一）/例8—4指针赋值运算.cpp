/* ָ�븳ֵ���� */
#include <stdio.h>

int main(void)
{
	int a,b,c,*p1,*p2;

	a=2;b=4;c=6;
	p1=&a,p2=&b;		/* p1ָ��a,p2ָ��b */
	printf("a=%d,b=%d,c=%d,*p1=%d,*p2=%d\n",a,b,c,*p1,*p2);

	p2=p1;p1=&c;		/* �ı�ָ��p1��p2��ֵ */
	printf("a=%d,b=%d,c=%d,*p1=%d,*p2=%d\n",a,b,c,*p1,*p2);

	return 0;
}