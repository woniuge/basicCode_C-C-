/* 逆序输出一个整数，假设正数和负数逆序输出结果一样 */
#include <stdio.h>

int main(void)
{
	int x;

	printf("enter x:");
	scanf("%d",&x);

	if(x<0)
		x=-x;
	  do{
		printf("%d",x%10);
		x=x/10;
		}while(x>0);

	printf("\n");

	return 0;
}