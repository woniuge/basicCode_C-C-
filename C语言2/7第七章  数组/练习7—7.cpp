/* 计算n阶方阵a的除副对角线，最后一列和最后一行以外的所有元素之和 */
#include <stdio.h>

int main(void)
{
	int i,j,n;
	double sum=0;
	int a[6][6];

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:\n",n*n);

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++)
			if((i+j)!=(n-1))
				sum+=a[i][j];
			
	printf("sum=%.0lf\n",sum);

	return 0;
}