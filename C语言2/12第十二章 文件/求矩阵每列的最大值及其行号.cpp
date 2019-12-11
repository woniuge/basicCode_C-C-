#include <stdio.h>
#define M 5
#define N 3

int main(void)
{
	int a[M][N],i,j,max[N],index[N];

	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			scanf("%d",&a[i][j]);
	for(j=0;j<N;j++)
	{
		max[j]=a[0][j];
		index[j]=0;
		for(i=1;i<M;i++)
			if(a[i][j]>max[j])
			{
				max[j]=a[i][j];
				index[j]=i;
			}
		printf("max[%d]=a[%d][%d]=%d\n",j,index[j],j,max[j]);
	}

	return 0;
}