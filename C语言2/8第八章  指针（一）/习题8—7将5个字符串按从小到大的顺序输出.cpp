/* 将5个字符串按从小到大的顺序输出 */
#include <stdio.h>
#include <string.h>
#define M 20

int main(void)
{
	int i,j;
	char s[6][M];

	printf("Input 5 strings:");
	for(i=1;i<=5;i++)
		scanf("%s",s[i]);

	for(i=2;i<6;i++)
		for(j=1;j<5;j++)
			if(strcmp(s[j],s[j+1])>0)
			{
				strcpy(s[0],s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],s[0]);
			}

	printf("After sorted:");
	int first=1;
	for(i=1;i<=5;i++)
	{
		if(first)
			first=0;
		else
			printf(" ");
		printf("%s",s[i]);
	}

	printf("\n");

	return 0;
}
