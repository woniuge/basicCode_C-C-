/* 输出21世纪所有的闰年leap year */
#include <stdio.h>

int main(void)
{
	int year;

	for(year=2000;year<=2100;year++)
	{
		if((year%4==0&&year%100!=0)||(year%400==0))
			printf("%d is a leap year.",year);
	}

	printf("\n");

	return 0;
}
