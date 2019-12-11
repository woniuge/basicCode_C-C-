/* 输入一个m*n矩阵a，求出各行元素之和并输出。 */
#include <stdio.h>

int main(void)
{
	int i,j,m,n,sum;
	int a[6][6];

	printf("enter m:");
	scanf("%d",&m);
	printf("enter n:");
	scanf("%d",&n);

	printf("enter %d*%d array:\n",m,n);
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(i=0;i<m;i++)
	{
		for(sum=0,j=0;j<n;j++)
			sum=sum+a[i][j];
		printf("sum of #%d is %d.\n",i,sum);
	}

	return 0;
}


