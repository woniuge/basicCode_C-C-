/* ͳ��һ��������λ�� */
#include <stdio.h>

int main(void)
{
	int count,number;							/* count��¼����number��λ�� */

	printf("enter a number:");
	scanf("%d",&number);

	count=0;
	if(number<0)
		number=-number;
	do{
		number=number/10;
		count++;
	}while(number!=0);							/* �ж�ѭ������ */

	printf("It contains %d digits.\n",count);

	return 0;
}