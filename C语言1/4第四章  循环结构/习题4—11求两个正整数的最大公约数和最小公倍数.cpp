/* ��������������m��n���������Լ������С������ */
#include <stdio.h>

int main(void)
{
	int m,n,j,k;

	do{
		printf("enter m:");
		scanf("%d",&m);
		printf("enter n:");
		scanf("%d",&n);
	  }while(m<0||n<0);

	j=m;
	while(j%n!=0)
		j=j+m;
	k=(m*n)/j;
		printf("���Լ����%d\n��С��������%d\n",k,j);

	return 0;
}