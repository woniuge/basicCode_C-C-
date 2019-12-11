/* 用数组输出一张九九乘法表，将乘数，被乘数和乘积放入一个二维数组中 */
#include <stdio.h>

int main(void)
{
	int i,j,n;
	int a[10][10];

	printf("Input n:");
	scanf("%d",&n);

	for(j=1;j<=n;j++)
		a[0][j]=j;
	for(i=1;i<=n;i++)
		a[i][0]=i;

	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			a[i][j]=a[i][0]*a[0][j];

	for(i=0;i<=n;i++)
	{
		if(i==0)
		{
			printf("*  ");
			for(j=1;j<=n;j++)
				printf("%-3d",a[i][j]);
		}
		else	
			for(j=0;j<=i;j++)
				printf("%-3d",a[i][j]);
		printf("\n");
	}

	return 0;
}