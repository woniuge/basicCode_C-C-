/*
	N����������ı߳�
	K������װ��������ʻ���������
	A�����Ϳ�ļ��ͷ���
	B������һ��Ӧ������
	C�������Ϳ�ķ���
*/

#include <stdio.h>
#include <process.h>

int main()
{
	FILE * fp1, * fp2;		//�����ļ�ָ��
	int N,K,A,B,C;
	int pri[101][101];		//��������λ�õļ���վ��״̬

	if((fp1 = fopen("input.txt","r")) == NULL)
	{
		printf("File open error! \n");
		exit(0);
	}
	
	fscanf(fp1,"%d %d %d %d %d",&N,&K,&A,&B,&C);

	int step[4][3] = {{-1,0,0},{0,-1,0},{1,0,B},{0,1,B}};	//��������ÿһ��λ�õ�״̬
	while(!feof(fp1))										//��ÿһ��λ�ø�ֵ
		for(int i = 1 ; i <= N ; i++)
			for(int j = 1 ; j <= N ; j++)
				fscanf(fp1,"%d",&pri[i][j]);


	struct NODE          //����������һ��λ��
	{
	  int x;
	  int y;
	 }node[101][101];
	

  	int f[101][101][2];			//��ά���飬��¼��С�����Լ�������ʻ��·��
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
		for(int x = 1 ; x <= N ; x++)			//��ʵxΪ�ڲ㣬yΪ��㣬��Ӧ�����Լ�s������ϵ
			for(int y = 1 ; y <= N ; y ++)
			{
				if (x==1 && y==1)
					continue;
				int minTempCost = 100;
				int tempCost;	//���赽�ﵱǰ��һλ�õķ���
				int tx,ty;		//���赱ǰ��һλ�õĺᡢ������
				int tempSide;		//���赽�ﵱǰ��һλ�û�����ʻ���������
				int minTempSide;
				for(int k = 0 ; k <= 3 ; k++)
				{
					tx = x + step[k][0];
					ty = y + step[k][1];

					if (tx<1 || tx>9 || ty<1 || ty>9)   //�߽��飡��
					  continue;
					
					tempCost = f[tx][ty][0] + step[k][2];
					tempSide = f[tx][ty][1] - 1;

					if (pri[x][y] == 1)        //�м���վ
					{
						tempCost += A;
						tempSide = K;
					}
					if ((tempSide == 0) && (pri[x][y] == 0) && (x!=N || y!=N)) //û�м���վ������û������
					{
					   tempCost += A + C;
					   tempSide = K;
					}
     
					if (tempCost < minTempCost)       //�ܹ���ǰ������
					{
					  minTempCost = tempCost;
					  minTempSide = tempSide;
					  tempx = tx;
					  tempy = ty;
					}
				}
    
					if (f[x][y][0] > minTempCost)      //���������Χ�и��õĽ⣬���滻f,node�ȼ�¼·��
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
	fprintf(fp2,"%d\n",f[9][9][0]);	//�����С���õ��ļ�

	for (i=1 ; i<=N ; i++)			//��������������ķ��õ��ļ�
	{
		for (int j=1 ; j<=N ; j++)
			fprintf(fp2,"%3d",f[j][i][0]);
		fprintf(fp2,"\n");
	}
 
	int x=9;						//��������յ����������С��·�����ļ�
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

  