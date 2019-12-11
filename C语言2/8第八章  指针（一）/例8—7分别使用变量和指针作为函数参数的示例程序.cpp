/* 分别使用变量和指针作为函数参数的示例程序 */
#include <stdio.h>
void swap1(int x,int y),swap2(int *px,int *py),swap3(int *px,int *py);

int main(void)
{
	int a=1,b=2;
	int *pa=&a,*pb=&b;

	swap1(a,b);			/* 使用变量a，b调用函数swap1（） */
	printf("After calling swap1:a=%d b=%d\n",a,b);

	a=1;
	b=2;
	swap2(pa,pb);		/* 使用指针pa，pb调用函数swap2（） */
	printf("After calling swap2:a=%d b=%d\n",a,b);

	a=1;
	b=2;
	swap3(pa,pb);		/* 使用指针pa，pb调用函数swap3（） */
	printf("After calling swap3:a=%d b=%d\n",a,b);

	return 0;
}

void swap1(int x,int y)		/* 形参改变 */
{
	int t;
	t=x;
	x=y;
	y=t;
}

void swap2(int *px,int *py)	/* 实参改变 */
{
	int t;
	t=*px;
	*px=*py;
	*py=t;
}

void swap3(int *px,int *py)	/* 指向改变 */
{
	int *pt;
	pt=px;
	px=py;
	py=pt;
}