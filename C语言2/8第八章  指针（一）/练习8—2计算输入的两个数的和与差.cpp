#include <stdio.h>
void sum_diff(float op1,float op2,float *psum,float *pdiff);

int main(void)
{
	float m,n;
	float sum,diff;
	
	printf("input m and n:");
	scanf("%f%f",&m,&n);

	sum_diff(m,n,&sum,&diff);

	printf("the sum of %f and %f is %f.\nthe difference of %f and %f is %f.\n",m,n,sum,m,n,diff);

	return 0;
}

void sum_diff(float op1,float op2,float *psum,float*pdiff)
{
	*psum=op1+op2;
	*pdiff=op1-op2;
}