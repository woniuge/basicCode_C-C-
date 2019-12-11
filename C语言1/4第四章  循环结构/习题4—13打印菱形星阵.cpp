/* ¥Ú”°¡‚–Œ–«’Û */
#include <stdio.h>

int main(void)
{
	int i,j,k,first;
	
	for(i=1;i<=4;i++)
	{
		for(j=8-2*i;j>0;j=j-2)
			printf("  ");
		first=1;
		for(k=1;k<=2*i-1;k++)
		{
			if(first)
			{
				printf("*");
				first=0;
			}
			else
				printf(" *");
		}

		printf("\n");
	}

	i=i-2;
	for(;i>0;i--)
	{
		for(j=8-2*i;j>0;j=j-2)
			printf("  ");
		first=1;
		for(k=1;k<=2*i-1;k++)
		{
			if(first)
			{
				printf("*");
				first=0;
			}
			else
				printf(" *");
		}

		printf("\n");	
	}

	return 0;
}