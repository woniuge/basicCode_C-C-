/* ����һ�������������ĸ�λ����֮�ͼ�λ�� */
#include <stdio.h>

int main(void)
{
	int x,sum,number;

	printf("enter x:");
	scanf("%d",&x);

	sum=number=0;
	  do{
			sum=sum+x%10;
			number++;
			x=x/10;
		}while(x!=0);

	  printf("sum=%d,numbers=%d\n",sum,number);

	  return 0;
}