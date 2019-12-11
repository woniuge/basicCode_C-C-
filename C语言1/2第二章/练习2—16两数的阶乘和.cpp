/* 输入两个正整数m和n，求m!+n! */
#include <stdio.h>

int main(void)
{
	int i,j,m,n;
	double product_m,product_n,product;

	printf("enter m:");
	scanf("%d",&m);
	printf("enter n:");
	scanf("%d",&n);
	
	product_m=product_n=1;
	for(i=1;i<=m;i++)
	{
		product_m=product_m*i;
	}
	
	for(j=1;j<=n;j++)
	{
		product_n=product_n*j;
	}

	product=product_m+product_n;

	printf("product=%.0f\n",product);

	return 0;
}