/* 使用动态内存分配的方法实现冒泡排序 */
#include <stdio.h>
#include <stdlib.h>
void swap(int *,int *);
void bubble(int *p,int n);

int main(void)
{
	int n,i,*p;

	printf("Enter n:");
	scanf("%d",&n);

	if((p=(int *)calloc(n,sizeof(int)))==NULL)
	{
		printf("Not able to allocate memory.\n");
		exit(1);
	}
	printf("Enter %d integers:",n);
	for(i=0;i<n;i++)
		scanf("%d",p+i);
	bubble(p,n);

	printf("After sorted:");
	int first=1;
	for(i=0;i<n;i++)
	{
		if(first)
			first=0;
		else
			printf(" ");
		printf("%d",*(p+i));
	}
	free(p);

	printf("\n");

	return 0;
}

void bubble(int *p,int n)
{
	int i,j;
	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
			if(*(p+j)>*(p+j+1))
				swap(p+j,p+j+1);
}

void swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}