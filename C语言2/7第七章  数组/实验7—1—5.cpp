/* 输入n个数，将其最小值与第一个数交换，并将其最大值与最后一个数交换 */
#include <stdio.h>

int main(void)
{
	int a[10];
	int n,i,index1,temp1,index2,temp2;

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:",n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	index1=0;
	for(i=1;i<n;i++)
		if(a[i]<a[index1])
			index1=i;

	temp1=a[index1];
	a[index1]=a[0];
	a[0]=temp1;

	index2=0;
	for(i=1;i<n;i++)
		if(a[i]>a[index2])
			index2=i;

	temp2=a[index2];
	a[index2]=a[n-1];
	a[n-1]=temp2;

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