/* 将n个整数从大到小排序后输出 */
#include <stdio.h>

int main(void)
{
	int n,i,index,k,temp;
	int a[100];				
	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:");
						
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
							
	for(k=0;k<n-1;k++)
	{
		index=k;
		for(i=k+1;i<n;i++)
			if(a[i]>a[index])
				index=i;
		temp=a[index];
		a[index]=a[k];
		a[k]=temp;
	}
							
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