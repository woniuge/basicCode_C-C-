/* 计算某日是该年的第几天 */
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
	int index;
	struct day_of_year date,*ptr;

	ptr=&date;
	printf("输入日期:");
	scanf("%d%d%d",&date.year,&date.month,&date.day);

	index=dayofyear(ptr);

	printf("该日期是%d年的第%d天.\n",ptr->year,index);

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