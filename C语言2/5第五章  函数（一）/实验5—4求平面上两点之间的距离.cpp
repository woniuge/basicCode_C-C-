/* 求平面上两点之间的距离 */
#include <stdio.h>
#include <math.h>
double dist(double x1,double y1,double x2,double y2);

int main(void)
{
	double x1,y1,x2,y2;

	printf("Input(x1,y1):");
	scanf("%lf%lf",&x1,&y1);
	printf("Input(x2,y2):");
	scanf("%lf%lf",&x2,&y2);

	printf("distance=%.2lf",dist(x1,y1,x2,y2));

	printf("\n");

	return 0;
}

double dist(double x1,double y1,double x2,double y2)
{
	double result;

	result=sqrt(pow(x1-x2,2)+pow(y1-y2,2));

	return result;
}