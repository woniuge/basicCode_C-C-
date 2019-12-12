#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;

	if((fp=fopen("f1.txt","r+"))==NULL)
	{
		printf("File open error!\n");
		exit(0);
	}

	fprintf(fp,"%s","xyz");
	if(fclose(fp))
	{
		printf("Can not close the file!\n");
		exit(0);
	}

	return 0;
}