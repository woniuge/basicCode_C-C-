/* 输入一个n阶方阵，将其转置后输出。a[i][j]=i*n+j+1(0<=i<=n-1,0<=j<=n-1) */
#include <stdio.h>

int main(void)
{
	int i,j,n,temp;
	int a[6][6];

	printf("enter n:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=i*n+j+1;

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i<=j)				/* 只遍历上三角形 */
			{
				temp=a[i][j];
				a[i][j]=a[j][i];
				a[j][i]=temp;
			}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}

	return 0;
}

/* 程序中，遍历上三角形的循环也可以写成：
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)		*/

