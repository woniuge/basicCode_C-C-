/* 三天打鱼两天晒网 */
#include <stdio.h>
struct day_of_year
{
	int year;
	int month;
	int day;
};
int dayofyear(struct day_of_year *p);

int main(void)
{
	int i,sum=0,flag;
	struct day_of_year date,*ptr;

	ptr=&date;
	printf("输入日期(自1990_1_1起):");
	scanf("%d%d%d",&date.year,&date.month,&date.day);

	for(i=1990;i<date.year;i++)
	{
		if(i%4==0&&i%100!=0||i%400==0)
			sum+=366;
		else
			sum+=365;
	}
	sum+=dayofyear(ptr);

	flag=sum%5;
	if(flag>=1&&flag<=3)
		printf("他在%d年%d月%d日打鱼.\n",date.year,date.month,date.day);
	else
		printf("他在%d年%d月%d日晒网.\n",date.year,date.month,date.day);

	return 0;
}

int dayofyear(struct day_of_year *p)
{
	int day=0,leap;
	int tab[2][13]=
	{
		{0,31,59,90,120,151,181,212,243,273,304,334,365},
		{0,31,60,91,121,152,182,213,244,274,305,335,366}
	};

	leap=(p->year%4==0&&p->year%100!=0||p->year%400==0);

	day=p->day+tab[leap][p->month-1];

	return day;
}