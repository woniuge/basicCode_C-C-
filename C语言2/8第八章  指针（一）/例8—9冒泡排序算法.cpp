/* 冒泡排序算法 */
#include <stdio.h>
void swap2 (int *,int *);
void bubble (int a[],int n);

int main(void)
{
	int n,a[8];
	int i;

	printf("Enter n (n<=8):");
	scanf("%d",&n);
	printf("Enter a[%d]:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	bubble(a,n);

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

void bubble (int a[],int n)					/* n是数组a中待排序元素的数量 */
{
	int i,j;
	for(i=1;i<n;i++)						/* 外部循环 */
		for(j=0;j<n-i;j++)					/* 内部循环 */
			if(a[j]>a[j+1])					/* 比较两个元素的大小 */
				swap2 (&a[j],&a[j+1]);		/* 如果前一个元素大，则交换 */
}

void swap2 (int *px,int *py)
{
	int t;
	t=*px;
	*px=*py;
	*py=t;
}

