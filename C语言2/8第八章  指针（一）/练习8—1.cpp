#include <stdio.h>

int main(void)
{
	int m,n=5,*p=&m;

	m=*p;
	printf("m=%d,n=%d\n",m,n);

	*p=*&n;
	printf("m=%d,n=%d\n",m,n);

/*	m=&n;
	printf("m=%d,n=%d\n",m,n);

	m=**p;
	printf("m=%d,n=%d\n",m,n);*/

	return 0;
}