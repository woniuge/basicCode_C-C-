/* ð�������㷨 */
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

void bubble (int a[],int n)					/* n������a�д�����Ԫ�ص����� */
{
	int i,j;
	for(i=1;i<n;i++)						/* �ⲿѭ�� */
		for(j=0;j<n-i;j++)					/* �ڲ�ѭ�� */
			if(a[j]>a[j+1])					/* �Ƚ�����Ԫ�صĴ�С */
				swap2 (&a[j],&a[j+1]);		/* ���ǰһ��Ԫ�ش��򽻻� */
}

void swap2 (int *px,int *py)
{
	int t;
	t=*px;
	*px=*py;
	*py=t;
}

