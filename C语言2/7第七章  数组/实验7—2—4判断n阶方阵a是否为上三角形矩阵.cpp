/* 判断n阶方阵a是否为上三角形矩阵 */
#include <stdio.h>

int main(void)
{
	int i,j,n;
	int a[6][6];

	printf("Input n:");
	scanf("%d",&n);
	printf("Input array:\n");

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&a[i][j]);

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
			if(a[i][j]!=0)
			{
				printf("NO\n");
				break;
			}

		if(j<i)
			break;
	}
	
	if(i==n)
		printf("YES\n");

	return 0;
}