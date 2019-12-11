//climbingRobot


#include <stdio.h>
#include <process.h>

#define M 100		//define rows of the matrix
#define N 50			//define columns of the matrix

int main()
{
	FILE * fp1, * fp2;		//define the pointers of file
	int a[M][N] = {0};		//�洢ԭʼ���ݣ�m���У�ÿ����n�����������ֱ��ʾ�����������ʵ�1��2������n�����õ�ʱ��
	int t[M][N] = {0};		//t[i][j]��ʾ��i���������ʵǵ�j��������ʱ�䣬t[i][0]��ʾ��i�����������ߵ���·��
	int m, n;				//m��n�ֱ��ʾ�����˵ĸ�����ÿ���������������ʵǵĸ߶�
	int i, j;
	int s , k = 0;			//s��ʾ�����˽����ʵǵ��ܸ߶�
	int sum = 0;			//�������ʵǵ�ʱ���ܺ�

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

	int min;					//ÿ����ѡ������Сֵ
	int xi;						//ÿ����ѡ������Сֵ���ڵ��к�
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
	fprintf(fp2,"������ԣ�\n");
	for(i = 1 ; i <= m ; i++)
		fprintf(fp2,"Robot%d:%dm_____%ds\n",i,t[i][0],a[i][t[i][0]]);


	fclose(fp1);
	fclose(fp2);
}
