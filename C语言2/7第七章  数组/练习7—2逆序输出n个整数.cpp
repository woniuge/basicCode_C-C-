/* 逆序输出n个整数 */
#include <stdio.h>

int main(void)
{
	int a[10];
	int n,i;

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:",n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	int first=1;
	for(i=n-1;i>=0;i--)
	{
		if(first)
			first=0;
		else
			printf(" ");
		printf("%d",a[i]);
	}

	printf("\n");

	return 0;
}