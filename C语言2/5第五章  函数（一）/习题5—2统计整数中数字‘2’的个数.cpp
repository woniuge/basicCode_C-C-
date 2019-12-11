/* 读入一个整数，统计并输出该整数中数字‘2’的个数。要求定义和调用函数
countdigit（number，digit），它的功能是统计整数number中数字digit的个数。
例如，countdigit（10090,0）的返回值是3。 */
#include <stdio.h>
int countdigit(int number,int digit);

int main(void)
{
	int digit,count,number;

	printf("enter number and digit:");
	scanf("%d%d",&number,&digit);

	count=countdigit(number,digit);
	
	printf("countdigit(%d,%d)=%d\n",number,digit,count);

	return 0;
}

int countdigit(int number,int digit)
{
	int result,item;

	result=0;
	do{
		item=number%10;
		if(item==digit)
			result++;
		number=number/10;
	  }while(number!=0);

	return result;
}

