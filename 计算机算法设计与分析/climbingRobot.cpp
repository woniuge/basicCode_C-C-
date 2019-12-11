//climbingRobot


#include <stdio.h>
#include <process.h>

#define M 100		//define rows of the matrix
#define N 50			//define columns of the matrix

int main()
{
	FILE * fp1, * fp2;		//define the pointers of file
	int a[M][N] = {0};		//存储原始数据，m行中，每行有n个正整数，分别表示机器人连续攀登1，2，…，n米所用的时间
	int t[M][N] = {0};		//t[i][j]表示第i个机器人攀登第j米所花的时间，t[i][0]表示第i个机器人所走的总路程
	int m, n;				//m和n分别表示机器人的个数、每个机器人最多可以攀登的高度
	int i, j;
	int s , k = 0;			//s表示机器人接力攀登的总高度
	int sum = 0;			//机器人攀登的时间总和

	if((fp1 = fopen("input.txt","r")) == NULL){
		printf("File open error! \n");
		exit(0);
	}
	
	fscanf(fp1,"%d%d%d",&m,&n,&s);

	while(!feof(fp1))
		for(i = 1 ; i <= m ; i++)
			for(j = 1 ; j <= n ; j++)
				fscanf(fp1,"%d",&a[i][j]);

	for(i = 1 ; i <= m ; i++)
	{
		t[i][1] = a[i][1];
		for(j = 2 ; j <= n ; j++)					
			t[i][j] = a[i][j] - a[i][j-1];
	}

	int min;					//每次挑选出的最小值
	int xi;						//每次挑选出的最小值所在的行号
	while(1){
		min = t[1][t[1][0] + 1];
		xi = 1;
		for(i = 2 ; i <= m ; i++)
		{
			if(t[i][t[i][0] + 1] < min)
			{
				min = t[i][t[i][0] + 1];
				xi = i;
			}
		}
		t[xi][0]++;
		k++;
		if(k == s)
			break;
	}

	if((fp2 = fopen("output.txt","w")) == NULL){
		printf("File open error! \n");
		exit(0);
	}

	for(i = 1 ; i <= m ; i++)
		sum += a[i][t[i][0]];
	fprintf(fp2,"%d\n",sum);
	fprintf(fp2,"分配策略：\n");
	for(i = 1 ; i <= m ; i++)
		fprintf(fp2,"Robot%d:%dm_____%ds\n",i,t[i][0],a[i][t[i][0]]);


	fclose(fp1);
	fclose(fp2);
}
