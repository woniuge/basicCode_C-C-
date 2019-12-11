/* 输出n以内的数字金字塔 */
#include <stdio.h>
void pyramid(int n);

int main(void)
{
	int m;

	printf("enter m:");
	scanf("%d",&m);

	pyramid(m);

	return 0;
}

void pyramid(int n)
{
	int i,j,first;

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n-i;j++)
			printf(" ");

		first=1;
		for(j=1;j<=i;j++)
		{
			if(first)
			{
				printf("%d",i);
				first=0;
			}
			else
				printf(" %d",i);
		}
		putchar('\n');
	}
}