/* ����һ��n�׷��󣬽���ת�ú������a[i][j]=i*n+j+1(0<=i<=n-1,0<=j<=n-1) */
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
			if(i<=j)				/* ֻ������������ */
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

/* �����У������������ε�ѭ��Ҳ����д�ɣ�
	for(i=0;i<n;i++)
		for(j=i;j<n;j++)		*/

