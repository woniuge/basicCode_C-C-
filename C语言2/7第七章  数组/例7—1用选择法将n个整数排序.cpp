/* ��ѡ�񷨽�n���������� */
#include <stdio.h>

int main(void)
{
	int n,i,index,k,temp;
	int a[100];				/* ����һ������a������10������Ԫ�� */

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:");
							/* �����������θ�������a��n��Ԫ��a��0��~a��n-1�� */
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
							/* ��n�������� */
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
							/* ���n������Ԫ�ص�ֵ */
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