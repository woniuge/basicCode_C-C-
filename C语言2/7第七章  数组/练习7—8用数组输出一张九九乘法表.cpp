/* ���������һ�žžų˷������������������ͳ˻�����һ����ά������ */
#include <stdio.h>

int main(void)
{
	int i,j;
	int a[10][10];

	for(j=0;j<=9;j++)
		a[0][j]=j;
	for(i=0;i<=9;i++)
		a[i][0]=i;

	for(i=1;i<=9;i++)
		for(j=1;j<=i;j++)
			a[i][j]=a[i][0]*a[0][j];

	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
			printf("%d*%d=%-3d",a[0][j],a[i][0],a[i][j]);
		printf("\n");
	}

	return 0;
}