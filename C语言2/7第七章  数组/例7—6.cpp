/* ����һ��3*2�Ķ�ά����a������Ԫ�ص�ֵ����ʽ���������������ʽ
���a��a��i����j��=i+j��0<=i<=2,0<=j<=1�� */
#include <stdio.h>

int main(void)
{
	int i,j;
	int a[3][2];

	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			a[i][j]=i+j;

	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}


	return 0;
}