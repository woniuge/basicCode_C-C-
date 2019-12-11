//MaxSumOfMatrixNumber


#include <stdio.h>
#include <process.h>

#define M 100		//define rows of the matrix
#define N 101			//define columns of the matrix

int main()
{
	FILE * fp1, * fp2;		//define the pointers of file
	int a[M][N] = {0};			
	int m, n;
	int i, j;
	int sum = 0;

	if((fp1 = fopen("input.txt","r")) == NULL){
		printf("File open error! \n");
		exit(0);
	}
	
	fscanf(fp1,"%d%d",&m,&n);

	while(!feof(fp1))
		for(i = 1 ; i <= m ; i++)
			for(j = 1 ; j <= n ; j++)
				fscanf(fp1,"%d",&a[i][j]);

	for(i = 1 ; i <= m ; i++)
	{
		a[i][0] = a[i][1];
		for(j = 2 ; j <= n ; j++)
		{
			if(a[i][j] > a[i][j - 1])
				a[i][0] = a[i][j];			//a[i][0] stores the maximum number of  the i line
		}
		sum += a[i][0];
	}
				

	if((fp2 = fopen("output.txt","w")) == NULL){
		printf("File open error! \n");
		exit(0);
	}

	fprintf(fp2,"%d",sum);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
