/* ���n����������ƽ������������λС���� */
#include <stdio.h>

int main(void)
{
	int n,i;
	int a[10];
	double sum=0;

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d integers:",n);

	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n;i++)
		sum+=a[i];

	printf("average is %.2lf\n",sum/n);

	return 0;
}