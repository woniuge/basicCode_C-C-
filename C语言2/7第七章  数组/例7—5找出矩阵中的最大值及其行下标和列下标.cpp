/* 找出矩阵中的最大值及其行下标和列下标 */
#include <stdio.h>

int main(void)
{
	int i,j,row,col;
	int a[3][2];

	printf("enter 6 integers:\n");
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			scanf("%d",&a[i][j]);

	for(i=0;i<3;i++)
	{
		int first=1;
			for(j=0;j<2;j++)
			{
				if(first)
					first=0;
				else
					printf(" ");
				printf("%d",a[i][j]);
			}
		printf("\n");
	}

	row=col=0;
	for(i=0;i<3;i++)
		for(j=0;j<2;j++)
			if(a[i][j]>a[row][col])
			{
				row=i;
				col=j;
			}

	printf("max=a[%d][%d]=%d\n",row,col,a[row][col]);

	return 0;
}