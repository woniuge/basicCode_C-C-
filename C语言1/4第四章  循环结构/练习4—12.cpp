/* �������һ�����������������͸�������������һ�� */
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