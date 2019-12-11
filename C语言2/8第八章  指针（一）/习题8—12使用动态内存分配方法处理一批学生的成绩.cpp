/* 使用动态内存分配方法处理一批学生的成绩 */
#include <stdio.h>
#include <stdlib.h>
double summ(double *ps,int n);
double maxx(double *pm,int n);
double minn(double *pn,int n);

int main(void)
{
	int i,n;
	double sum=0,max,min,*p;

	printf("Input n:");
	scanf("%d",&n);
	if((p=(double *)calloc(n,sizeof(double)))==NULL)
	{
		printf("Not able to allocate memory.\n");
		exit(1);
	}
	printf("Input %d scores:",n);
	for(i=0;i<n;i++)
		scanf("%lf",p+i);
	
	sum=summ(p,n);
	max=maxx(p,n);
	min=minn(p,n);
	printf("average=%.2lf,max=%.2lf,min=%.2lf\n",sum/n,max,min);

	free(p);

	return 0;
}

double summ(double *ps,int n)
{
	int i;
	double sum=0;

	for(i=0;i<n;i++)
		sum+=*(ps+i);

	return sum;
}

double maxx(double *pm,int n)
{
	int i;
	double max;

	max=*pm;
	for(i=1;i<n;i++)
		if(*(pm+i)>max)
			max=*(pm+i);

	return max;
}

double minn(double *pn,int n)
{
	int i;
	double min;

	min=*pn;
	for(i=1;i<n;i++)
		if(*(pn+i)<min)
			min=*(pn+i);

	return min;
}