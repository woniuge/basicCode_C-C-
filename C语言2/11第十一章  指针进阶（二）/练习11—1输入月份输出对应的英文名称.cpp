/* 输入月份输出对应的英文名称 */
#include <stdio.h>

int main(void)
{
	int x;
	char *month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};

	printf("Enter x:");
	scanf("%d",&x);

	printf("%s\n",month[x-1]);

	return 0;
}