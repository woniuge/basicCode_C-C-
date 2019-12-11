/* 输入两个正整数m和n，求其最大公约数和最小公倍数 */
#include <stdio.h>

int main(void)
{
	int m,n,j,k;

	do{
		printf("enter m:");
		scanf("%d",&m);
		printf("enter n:");
		scanf("%d",&n);
	  }while(m<0||n<0);

	j=m;
	while(j%n!=0)
		j=j+m;
	k=(m*n)/j;
		printf("最大公约数是%d\n最小公倍数是%d\n",k,j);

	return 0;
}