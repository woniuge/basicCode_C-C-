#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	long num;
	char stname[20];
	int score;

	if((fp=fopen("f.txt","r"))==NULL)
	{
		printf("File open error!\n");
		exit(0);
	}

	while(!feof(fp))
	{
		fscanf(fp,"%ld%s%d",&num,stname,&score);
		printf("%ld  %-6s  %d\n",num,stname,score);
	};

	if(fclose(fp))
	{
		printf("Can not close the file!\n");
		exit(0);
	}

	return 0;
}