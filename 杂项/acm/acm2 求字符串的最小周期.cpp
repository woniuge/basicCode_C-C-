/* 如果一个字符串可以由某个长度为k的字符串重复多次得到，
我们说该字符串以k为周期。例如，abcabcabcabc以3为周期（
注意，它也以6和12为周期）。输入一个长度不超过80的串，输
出它的最小周期cycle。杨丽输入：hohoho  样例输出：2 */
#include <stdio.h>

int main(void)
{
	int i,cycle;
	char a[90];

	printf("enter a string:");
	
	for(i=1;(a[i]=getchar())=='\n';i++)
		a[i]=getchar();


}