/* 显示所有的命令行参数 */
#include <stdio.h>

int main(int argc,char *argv[])
{
	int k;

	int first=1;
	for(k=1;k<argc;k++)
	{
		if(first)
			first=0;
		else
			printf(" ");
		printf("%s",argv[k]);
	}

	printf("\n");

	return 0;
}