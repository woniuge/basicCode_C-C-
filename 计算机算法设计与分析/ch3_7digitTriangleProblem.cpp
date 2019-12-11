//ch3_7digitTriangleProblem


#include <stdio.h>
#include <process.h>

#define N 101			//define maximum of the line number
//#define MAX(x,y) x >= y? x:y

//int maxsum(int a[N][N]);
int Cost(int n,int k);

int a[N][N]={0};
int main()
{
	FILE * fp1, * fp2;		//define the pointers of file
//	int a[N][N];			//a[0][0] define the line number
	int i, j;
	int sum;

	if((fp1 = fopen("input.txt","r")) == NULL){
		printf("File open error! \n");
		exit(0);
	}
	
	fscanf(fp1,"%d",&a[0][0]);

	while(!feof(fp1))
		for(i = 1 ; i <= a[0][0] ; i++)
			for(j = 1 ; j <= i ; j++)
				fscanf(fp1,"%d",&a[i][j]);

//	sum = maxsum(a);
	Cost(1,1);

	if((fp2 = fopen("output.txt","w")) == NULL){
		printf("File open error! \n");
		exit(0);
	}

	fprintf(fp2,"%d",sum);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

/*
int maxsum(int a[N][N])
{
	int i = a[0][0];
	int b[N] = {0};
	int j;

	for(--i ; i >= 0 ; i--)
		for(j = 1 ; j <= i+1 ; j++)
			b[j] = MAX(a[i+1][j] + b[j] , a[i+1][j] + b[j+1]);
		
	return b[1];
}
*/

int Cost(int n,int k)
{
	int sum,x,y;
	int len = a[0][0];

	if (n == len)
		sum = a[n][k];
	else if (n > len)
		sum = 0;
	else{
		x = a[n][k]+Cost(n+1,k);
		y = a[n][k]+Cost(n+1,k+1);
		if (x >= y)
			sum = x;
		else 
			sum = y;
	}
		

	return sum;
}


/*
 int   MAXS(int i,int j){
¡¡¡¡ int x,y,max;
        if(i==n){
           max=A[i,j]
        }else{
         x=MAXS(i+1,j)
         y=MAXS(i+1,j+1)
         if(x>y) max=X+A[i,j]
         else     max= Y+A[i,j]; }
Return max;
}¡¡
*/