/* 使用指针计算数组元素之和 */
#include <stdio.h>

int main(void)
{
	int i,a[10],*p;
	long sum=0;

	printf("Enter 10 integers:");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(p=a;p<=a+9;p++)
		sum=sum+*p;

	printf("sum=%ld\n",sum);

	return 0;
}