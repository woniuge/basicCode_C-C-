/* 猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，
还不过瘾，又多吃了一个。第二天早上将剩下的桃子吃掉一半，
又多吃了一个。以后每天早上都吃了前一天剩下的一半零一个。
到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了
多少桃子？（提示：逆向思维，从后往前推。） */
#include <stdio.h>

int main(void)
{
	int i,n;

	n=1;
	for(i=1;i<10;i++)
		n=2*(n+1);

	printf("n=%d\n",n);

	return 0;
}