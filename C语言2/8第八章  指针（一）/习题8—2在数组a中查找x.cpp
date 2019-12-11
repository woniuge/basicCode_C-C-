/* 在数组a中查找x */
#include <stdio.h>
int search(int list[],int n,int x);

int main(void)
{
	int i,n,x,a[10];

	do
	{
		printf("Enter n(<=10):");
		scanf("%d",&n);
	}while(n<=0||n>11);
	printf("Enter %d integers:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter x:");
	scanf("%d",&x);

	if(search(a,n,x)==-1)
		printf("Not found\n");
	else
		printf("%d\n",search(a,n,x));

	return 0;
}

int search(int list[],int n,int x)
{
	int i;

	for(i=0;i<n;i++)
		if(list[i]==x)
		{
			return i;
			break;
		}

	if(i==n)
		return -1;
}
