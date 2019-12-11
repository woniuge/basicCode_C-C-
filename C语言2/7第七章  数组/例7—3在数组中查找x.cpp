/* 输入5个整数，将它们存入数组a中，再输入一个数x，然后在数组中查找x，
如果找到，输出相应的下标，否则，输出“Not Found”。 */
#include <stdio.h>

int main(void)
{
	int i,flag=1,x;
	int a[5];

	printf("enter 5 integers:");
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);

	printf("enter x:");
	scanf("%d",&x);

	for(i=0;i<5;i++)
		if(x==a[i])
		{
			printf("Index is %d\n",i);
			flag=0;
			break;
		}

	if(flag)
		printf("Not Found\n");

	return 0;
}
