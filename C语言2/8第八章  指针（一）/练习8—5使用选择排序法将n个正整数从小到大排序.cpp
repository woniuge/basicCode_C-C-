/* 使用选择排序法将n个正整数从小到大排序 */
#include <stdio.h>
void swap2 (int *,int *);
void choice (int a[],int n);

int main(void)
{
	int n,a[8];
	int i;

	printf("Enter n (n<=8):");
	scanf("%d",&n);
	printf("Enter a[%d]:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	choice (a,n);

	printf("After sorted,a[%d]=",n);
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

void choice (int a[],int n)					/* n是数组a中待排序元素的数量 */
{
	int i,j,index;

	for(i=0;i<n-1;i++)						/* 外部循环 */
	{
		index=i;
		for(j=i+1;j<n;j++)					/* 内部循环 */
			if(a[j]<a[index])				/* 比较两个元素的大小 */
				index=j;					/* 如果前一个元素小，则index=j */
		swap2 (&a[i],&a[index]);			/* 交换 */
	}
}

void swap2 (int *px,int *py)
{
	int t;
	t=*px;
	*px=*py;
	*py=t;
}