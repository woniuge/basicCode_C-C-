/* 使用指针作为函数参数返回多个函数值的示例，
输入年份和天数  输出对应的年月日 */
#include <stdio.h>
void month_day(int year,int yearday,int *pmonth,int *pday);

int main(void)
{
	int year,month,day,yearday;

	printf("input year and yearday:\n");
	scanf("%d%d",&year,&yearday);

	month_day(year,yearday,&month,&day);

	printf("%d_%d_%d \n",year,month,day);

	return 0;
}

void month_day(int year,int yearday,int *pmonth,int *pday)
{
	int k,leap;
	int tab[2][13]=
	{
		{0,31,28,31,30,31,30,31,31,30,31,30,31},
		{0,31,29,31,30,31,30,31,31,30,31,30,31}
	};

	/* 判断闰年，当year是闰年时，leap=1；当year是非闰年时，leap=0 */
	leap=(year%4==0&&year%100!=0||year%400==0);

	for(k=1;yearday>tab[leap][k];k++)
		yearday-=tab[leap][k];
	*pmonth=k;
	*pday=yearday;
}