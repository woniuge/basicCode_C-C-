/* 输出n个数中的最大值及其下标并与最后一个数交换 */
#include <stdio.h>

int main(void)
{
	int a[10];
	int n,i,index,temp;

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:",n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	index=0;
	for(i=1;i<n;i++)
		if(a[i]>a[index])
			index=i;

	printf("max is %d\tsub is %d\n",a[index],index);

	temp=a[index];
	a[index]=a[n-1];
	a[n-1]=temp;

	int first=1;
	for(i=0;i<n;i++)
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