/* 找出数组的最小值和它所对应的下标 */
#include <stdio.h>

int main(void)
{
	int i,n,index;
	int a[10];

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	/* 找最小值a[index] */
	index=0;					/* 假设a[0]是最小值，即下标为0的元素最小 */
	for(i=1;i<n;i++)
		if(a[i]<a[index])		/* 如果a[i]比假设的最小值还小 */
			index=i;			/* 再假设a[i]是新的最小值，即下标为i的元素最小 */

	/* 输出最小值和对应的下标 */
	printf("min is %d\tsub is %d\n",a[index],index);

	return 0;
}
