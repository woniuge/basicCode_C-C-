/* �ֱ�ʹ�ñ�����ָ����Ϊ����������ʾ������ */
#include <stdio.h>
void swap1(int x,int y),swap2(int *px,int *py),swap3(int *px,int *py);

int main(void)
{
	int a=1,b=2;
	int *pa=&a,*pb=&b;

	swap1(a,b);			/* ʹ�ñ���a��b���ú���swap1���� */
	printf("After calling swap1:a=%d b=%d\n",a,b);

	a=1;
	b=2;
	swap2(pa,pb);		/* ʹ��ָ��pa��pb���ú���swap2���� */
	printf("After calling swap2:a=%d b=%d\n",a,b);

	a=1;
	b=2;
	swap3(pa,pb);		/* ʹ��ָ��pa��pb���ú���swap3���� */
	printf("After calling swap3:a=%d b=%d\n",a,b);

	return 0;
}

void swap1(int x,int y)		/* �βθı� */
{
	int t;
	t=x;
	x=y;
	y=t;
}

void swap2(int *px,int *py)	/* ʵ�θı� */
{
	int t;
	t=*px;
	*px=*py;
	*py=t;
}

void swap3(int *px,int *py)	/* ָ��ı� */
{
	int *pt;
	pt=px;
	px=py;
	py=pt;
}