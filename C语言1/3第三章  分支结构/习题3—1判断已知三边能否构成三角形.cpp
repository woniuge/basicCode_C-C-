/* 判断已知三边能否构成三角形并求其面积area和周长perimeter */
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a,b,c,s,area,perimeter;

	printf("enter a b c:");
	scanf("%lf%lf%lf",&a,&b,&c);

	if((a+b>c)&&(a+c>b)&&(b+c>a))
	{
		s=(a+b+c)/2;
		area=sqrt(s*(s-a)*(s-b)*(s-c));
		perimeter=a+b+c;
		printf("area=%.2f, perimeter=%.2f\n",area,perimeter);
	}
	else
		printf("These sides do not correspond to a valid triangle.\n");

	return 0;	
}