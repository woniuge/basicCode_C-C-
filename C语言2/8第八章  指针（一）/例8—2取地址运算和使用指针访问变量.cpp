/* ȡ��ַ�����ʹ��ָ����ʱ��� */
#include <stdio.h>

int main(void)
{
	int a=3,*p;						/* �������ͳ���a������ָ��p */

	p=&a;							/* �ѱ���a�ĵ�ַ����ָ��p����pָ��a */
	printf("a=%d,*p=%d\n",a,*p);	/* �������a��ֵ��ָ��p��ָ�������ֵ */
	*p=10;							/* ��ָ��p��ָ��ı�����ֵ���൱�ڶԱ���a��ֵ */
	printf("a=%d,*p=%d\n",a,*p);
	printf("enter a:");
	scanf("%d",&a);
	printf("a=%d,*p=%d\n",a,*p);
	(*p)++;							/* ��ָ����ָ��ı�����1 */
	printf("a=%d,*p=%d\n",a,*p);

	return 0;
}