/* 用选择法将n个整数排序 */
#include <stdio.h>

int main(void)
{
	int n,i,index,k,temp;
	int a[100];				/* 定义一个数组a，它有10个整型元素 */

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:");
							/* 将输入数依次赋给数组a的n个元素a【0】~a【n-1】 */
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
							/* 对n个数排序 */
	for(k=0;k<n-1;k++)
	{
		index=k;
		for(i=k+1;i<n;i++)
			if(a[i]<a[index])
				index=i;
		temp=a[index];
		a[index]=a[k];
		a[k]=temp;
	}
							/* 输出n个数组元素的值 */
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