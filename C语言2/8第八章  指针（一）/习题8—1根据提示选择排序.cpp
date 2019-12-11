/* 根据提示选择排序 */
#include <stdio.h>
void sort1(int a[],int n);
void sort2(int a[],int n);
void swap(int *,int *);

int main(void)
{
	int i,n,a[10];
	char ch;

	do
	{
		printf("Enter n(<=10):");
		scanf("%d",&n);
	}while(n<=0||n>11);
	printf("Enter %d integers:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	do
	{
		printf("A:从小到大\nD:从大到小\nEnter your choice:");
		getchar();
		scanf("%c",&ch);
	}while(ch!='A'&&ch!='D');
	if(ch=='A')
		sort1(a,n);
	else
		if(ch=='D')
			sort2(a,n);
	printf("After sorted:");
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

void sort1(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j]>a[j+1])
				swap(&a[j],&a[j+1]);
}

void sort2(int a[],int n)
{
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(a[j]<a[j+1])
				swap(&a[j],&a[j+1]);
}

void swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}