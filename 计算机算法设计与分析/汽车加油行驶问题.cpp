/*
	N：方形网格的边长
	K：汽车装满油能行驶的网格边数
	A：遇油库的加油费用
	B：后退一格应付费用
	C：增设油库的费用
*/

#include <stdio.h>
#include <process.h>

int main()
{
	FILE * fp1, * fp2;		//定义文件指针
	int N,K,A,B,C;
	int pri[101][101];		//定义所有位置的加油站的状态

	if((fp1 = fopen("input.txt","r")) == NULL)
	{
		printf("File open error! \n");
		exit(0);
	}
	
	fscanf(fp1,"%d %d %d %d %d",&N,&K,&A,&B,&C);

	int step[4][3] = {{-1,0,0},{0,-1,0},{1,0,B},{0,1,B}};	//定义来自每一个位置的状态
	while(!feof(fp1))										//给每一个位置赋值
		for(int i = 1 ; i <= N ; i++)
			for(int j = 1 ; j <= N ; j++)
				fscanf(fp1,"%d",&pri[i][j]);


	struct NODE          //定义来自哪一个位置
	{
	  int x;
	  int y;
	 }node[101][101];
	

  	int f[101][101][2];			//三维数组，记录最小费用以及还能行驶的路程
	for (int i=1 ; i<=N ; i++)
		for (int j=1 ; j<=N ; j++)
			f[i][j][0] = 100;

	for (i=1 ; i<=N ; i++)
		for (int j=1 ; j<=N ; j++)
			f[i][j][1]=K;

	f[1][1][0] = 0;
	f[1][1][1] = K;

	int count = 1;
	int tempx;
	int tempy;
	while(count)
	{
		count = 0;
		for(int x = 1 ; x <= N ; x++)			//其实x为内层，y为外层，对应坐标以及s的坐标系
			for(int y = 1 ; y <= N ; y ++)
			{
				if (x==1 && y==1)
					continue;
				int minTempCost = 100;
				int tempCost;	//假设到达当前下一位置的费用
				int tx,ty;		//假设当前下一位置的横、纵坐标
				int tempSide;		//假设到达当前下一位置还能行驶的网格边数
				int minTempSide;
				for(int k = 0 ; k <= 3 ; k++)
				{
					tx = x + step[k][0];
					ty = y + step[k][1];

					if (tx<1 || tx>9 || ty<1 || ty>9)   //边界检查！！
					  continue;
					
					tempCost = f[tx][ty][0] + step[k][2];
					tempSide = f[tx][ty][1] - 1;

					if (pri[x][y] == 1)        //有加油站
					{
						tempCost += A;
						tempSide = K;
					}
					if ((tempSide == 0) && (pri[x][y] == 0) && (x!=N || y!=N)) //没有加油站，并且没有油了
					{
					   tempCost += A + C;
					   tempSide = K;
					}
     
					if (tempCost < minTempCost)       //能够往前继续走
					{
					  minTempCost = tempCost;
					  minTempSide = tempSide;
					  tempx = tx;
					  tempy = ty;
					}
				}
    
					if (f[x][y][0] > minTempCost)      //如果发现周围有更好的解，则替换f,node等记录路径
					{
					 count++;
					 f[x][y][0] = minTempCost;
					 f[x][y][1] = minTempSide;
					 node[x][y].x = tempx;
					 node[x][y].y = tempy;
					}
			}
	}

	if((fp2 = fopen("output.txt","w")) == NULL){
		printf("File open error! \n");
		exit(0);
	}
	fprintf(fp2,"%d\n",f[9][9][0]);	//输出最小费用到文件

	for (i=1 ; i<=N ; i++)			//输出到达各点所需的费用到文件
	{
		for (int j=1 ; j<=N ; j++)
			fprintf(fp2,"%3d",f[j][i][0]);
		fprintf(fp2,"\n");
	}
 
	int x=9;						//输出到达终点所需费用最小的路径到文件
	int y=9;
	while ((x!=1)||(y!=1))
	{
		int tempx;
		fprintf(fp2,"(%d,%d),%d\n",x,y,f[x][y][0]);
		tempx=x;
		x=node[x][y].x;
		y=node[tempx][y].y;
	}
	fprintf(fp2,"(%d,%d),%d\n",x,y,f[x][y][0]);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

  