/* 定义和调用求阶乘函数生成阶乘表 */
#include <stdio.h>
double fact(int n);							/* 自定义函数的声明 */

int main(void)
{
	int i,n;
	double result;

	printf("enter n:");						/* 输入提示 */
	scanf("%d",&n);

	for(i=0;i<=n;i++)
	{
		result=fact(i);						/* 调用自定义函数fact（i）计算i! */
		printf("%d!=%.0f\n",i,result);
	}

	return 0;
}

/* 定义求n!的函数 */
double fact(int n)							/* 函数首部 */
{
	int i;
	double product;							/* 变量product用于存放结果（阶乘的值） */

	/* 计算n! */
	product=1;								/* 置阶乘product的初值为1 */
	for(i=1;i<=n;i++)						/* 循环n次，计算n! */
	{
		product=product*i;
	}

	return product;							/* 将结果回送主函数 */
}