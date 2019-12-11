/* 在字符串中查找某字符，若找到，输出其最大下标，否则输出Not Found */
#include <stdio.h>

int main(void)
{
	int i,index;
	char str[80];
	char ch;

	printf("Input a string:");
	i=0;
	while((str[i]=getchar())!='\n')
		i++;
	str[i]='\0';

	printf("Input a character:");
	scanf("%c",&ch);

	int flag=0;
	for(i=0;str[i]!='\0';i++)
		if(str[i]==ch)
		{
			index=i;
			flag=1;
		}

	if(flag)
		printf("index=%d\n",index);
	else
		printf("Not Found\n");

	return 0;
}
