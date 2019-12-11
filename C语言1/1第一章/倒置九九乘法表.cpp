#include<stdio.h>

int main(void)
{
	int i,j,n;
	
	printf("enter n: ");
	scanf("%d",&n);
	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	
	for(i=1;i<=n;i++)
	{	
		for(j=2;j<=i;j++)
		{
		printf("       ");
		}

		for(j=i;j<=n;j++)
		{
			printf("%d*%d=%-2d ",i,j,i*j);
		}
		printf("\n");
	}

	printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	return 0;
}
