/* �ҳ��������Сֵ��������Ӧ���±�,����Сֵ���һ��������������������n���� */
#include <stdio.h>

int main(void)
{
	int i,n,index,temp;
	int a[10];

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	/* ����Сֵa[index] */
	index=0;					/* ����a[0]����Сֵ�����±�Ϊ0��Ԫ����С */
	for(i=1;i<n;i++)
		if(a[i]<a[index])		/* ���a[i]�ȼ������Сֵ��С */
			index=i;			/* �ټ���a[i]���µ���Сֵ�����±�Ϊi��Ԫ����С */

	/* �����Сֵ�Ͷ�Ӧ���±� */
	printf("min is %d\tsub is %d\n",a[index],index);

	/* ����Сֵ���һ��������������������n���� */
	temp=a[index];
	a[index]=a[0];
	a[0]=temp;
	for(i=0;i<n;i++)
		printf("%2d",a[i]);

	printf("\n");

	return 0;
}
