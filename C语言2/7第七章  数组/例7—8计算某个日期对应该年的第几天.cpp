/* 计算某个日期对应该年的第几天 */
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
	int k,leap;
	int tab[2][13]=
	{
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};

	/* 判断闰年，当year是闰年时，leap=1；当year是非闰年时，leap=0 */
	leap=(year%4==0&&year%100!=0||year%400==0);

	for(k=1;k<month;k++)
		day=day+tab[leap][k];

	return day;
}