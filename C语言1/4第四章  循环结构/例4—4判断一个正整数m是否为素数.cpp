/* �ж�һ��������m�Ƿ�Ϊ���� */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,m;

	printf("enter a number:");
	scanf("%d",&m);

	if(m==1)
			printf("No!\n");
	else
	{
		for (i=2;i<=sqrt(m);i++)
			if(m%i==0)
				break;							/* ��m�ܱ�ĳ��i��������m������������ǰ����ѭ�� */
		if(i>sqrt(m))							/* ���ѭ������������˵��m���ܱ��κ�һ��i��������m������ */
			printf("%d is a prime number!\n",m);
		else
			printf("No!\n");
	}

	return 0;
}