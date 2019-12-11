 /* 找到矩阵a的鞍点(在该行上最大，在该列上最小) */
#include <stdio.h>

int main(void)
{
	int i,j,k,n,row,col;
	int a[6][6];

	printf("Input n:");
	scanf("%d",&n);
	printf("Input array:\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(i=0;i<n;i++)
	{
		row=i;
		col=0;
		for(j=0;j<n;j++)
			if(a[i][j]>a[row][col])
			{
				row=i;
				col=j;
			}
		for(k=0;k<n;k++)
			if(a[k][col]<a[row][col])
				break;
		if(k==n)
		{
			printf("a[%d][%d]=%d\n",row,col,a[row][col]);
			break;
		}
		else
			continue;
	}

	if(i==n)
		printf("NO\n");

	return 0;
}