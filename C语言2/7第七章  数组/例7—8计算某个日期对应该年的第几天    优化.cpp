/* 计算某个日期对应该年的第几天    优化 */
#include <stdio.h>
int day_of_year(int year,int month,int day);

int main(void)
{
	int year,month,day,index;

	printf("enter year,month and day:\n");
	scanf("%d%d%d",&year,&month,&day);

	index=day_of_year(year,month,day);

	printf("这天是该年的第%d天.\n",index);

	return 0;
}

int day_of_year(int year,int month,int day)
{
	int leap;
	int tab[2][13]=
	{
		{0,31,59,90,120,151,181,212,243,273,304,334,365},
		{0,31,60,91,121,152,182,213,244,274,305,335,366}
	};

	leap=(year%4==0&&year%100!=0||year%400==0);

	day=day+tab[leap][month-1];

	return day;
}