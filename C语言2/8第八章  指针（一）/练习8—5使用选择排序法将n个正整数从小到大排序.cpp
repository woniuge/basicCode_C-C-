/* ʹ��ѡ�����򷨽�n����������С�������� */
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

void choice (int a[],int n)					/* n������a�д�����Ԫ�ص����� */
{
	int i,j,index;

	for(i=0;i<n-1;i++)						/* �ⲿѭ�� */
	{
		index=i;
		for(j=i+1;j<n;j++)					/* �ڲ�ѭ�� */
			if(a[j]<a[index])				/* �Ƚ�����Ԫ�صĴ�С */
				index=j;					/* ���ǰһ��Ԫ��С����index=j */
		swap2 (&a[i],&a[index]);			/* ���� */
	}
}

void swap2 (int *px,int *py)
{
	int t;
	t=*px;
	*px=*py;
	*py=t;
}