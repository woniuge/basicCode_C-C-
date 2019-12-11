/* ÄæĞòÊä³öÒ»¸ö×Ö·û´® */
#include <stdio.h>

int main(void)
{
	int i,k,temp;
	char str[80];

	printf("Input a string:");
	i=0;
	while((str[i]=getchar())!='\n')
		i++;
	str[i]='\0';

	k=i-1;
	for(i=0;i<k;i++)
	{
		temp=str[i];
		str[i]=str[k];
		str[k]=temp;
		k--;
	}

	for(i=0;str[i]!='\0';i++)
		putchar(str[i]);

	printf("\n");

	return 0;
}