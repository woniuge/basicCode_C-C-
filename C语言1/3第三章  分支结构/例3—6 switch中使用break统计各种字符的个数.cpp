/* 统计字符，包括空格或回车，数字字符和其他字符 */
#include <stdio.h>

int main(void)
{
	int  i,n,blank,digit,other;							/* 定义3个变量分别存放统计结果 */
	char ch;

	printf("enter n:");									/* 提示输入统计总数n */
	scanf("%d",&n);
	printf("enter %d characters:\n",n);					/* 输入提示 */
		ch=getchar();									/* 拿走一个字符 */

	blank=digit=other=0;								/* 置存放统计结果的3个变量的初值为零 */
	for(i=1;i<=n;i++)									/* 循环执行了n次 */
	{
		ch=getchar();									/* 输入一个字符 */
		/* 在switch语句中灵活应用break */
		switch(ch)
		{
			case' ':										/* 语句段为空，请注意空格的表示 */
			case'\n':
				blank++;								/* 两个常量表达式' '和'\n'共用该语句段 */
				break;									/* 跳出switch语句 */
			case'0':case'1':case'2':case'3':case'4':
			case'5':case'6':case'7':case'8':case'9':
				digit++;								/* 10个常量表达式'0'~'9'共用该语句段 */
				break;									/* 跳出switch语句 */
			default:
				other++;								/* 累加其他字符 */
				break;									/* 跳出switch语句 */
		}
	}

	printf("blank=%d,digit=%d,other=%d\n",blank,digit,other);

	return 0;
}