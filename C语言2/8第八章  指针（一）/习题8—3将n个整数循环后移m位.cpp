/* 将n个整数循环后移m位 */
#include <stdio.h>
void mov(int *,int,int);

int main(void)
{
	int m,n,i,a[80],*p;

	printf("Input n,m:");
	scanf("%d%d",&n,&m);

	for(p=a,i=0;i<n;i++)
		scanf("%d",p++);
	mov(a,n,m);
	printf("After move:");
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

void mov(int *s,int n,int m)
{
	int i,j,t;

	for(i=0;i<m;i++)
	{
		t=s[n-1];
		for(j=n-1;j>0;j--)
			s[j]=s[j-1];
		s[j]=t;
	}
}