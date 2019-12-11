//�㷨ʵ����2_1_���͹ܵ�����


#include <stdio.h>
#include <process.h>
#include <math.h>

#define M 10000

struct point
{
	int x;
	int y;
};

int sum(int bl[],int n);
void qsort(int arr[],int left,int right);
void swap(int *a, int *b);

int main(void)
{
	FILE * fp1, * fp2;			//�����ļ�ָ��
	struct point a[M];			//����洢��������Ľṹ����
	int n;						//�����;���
	int b[M];					//����洢�;�λ�������������
	int i = 0;
	int s;

	if((fp1 = fopen("input.txt","r")) == NULL){
		printf("File open error! \n");
		exit(0);
	}

	fscanf(fp1,"%d",&n);
	while(!feof(fp1))
		fscanf(fp1,"%d %d",&a[i++].x,&a[i].y);

	for(int j = 0 ; j <= i-1 ; j++)
		b[j] = a[j].y;

	qsort(b, 0, j-1);

	s = sum(b,n);

	if((fp2 = fopen("output.txt","w")) == NULL){
		printf("File open error! \n");
		exit(0);
	}

	fprintf(fp2,"%d",s);

	fclose(fp1);
	fclose(fp2);

	return 0;
}

int sum(int bl[],int n)
{
	int middle;
	int result = 0;
	int i;

	middle = n/2;

	for(i = 0 ; i < n ; i++)
		result = result + abs(bl[i] - bl[middle]);

	return result;
}




void swap(int *a, int *b)        //swap()����ʵ�ֽ�����������Ԫ�ص�ֵ�Ĺ��ܡ�
{ 
  int t;
  t = *a; 
  *a = *b; 
  *b = t; 
}

void qsort(int arr[],int left,int right)    
{                                      
	 int i = left;                   //��i����߿�ʼɨ�����顣         
     int j = right;                  //��j���ұ߿�ʼɨ�����顣
     
	 int key = arr[(i+j)/2];             //������һ����׼ֵkey���˳�������������м�λ�õ�Ԫ��Ϊ��׼ֵ��
 
	 while(i < j)         //��Ϊ����i>=jʱ��i��ָ�������Ԫ�أ�����j�Ѿ����ʣ��жϹ���Ԫ�أ���������iȥ���ʣ��ж��ˡ�                    
        {
            for(;(i < right)&&(arr[i] < key);i++);
			for(;(j > left)&&(arr[j] > key);j--);  
			if (i <= j)  
              {
                 if ( i != j)
					 swap(&arr[i],&arr[j]);
                 i++;
                 j--;
              }
		}
     if (i < right)     //��Ϊ������ĵݹ���ã�����iΪ��߽磬rightΪ�ұ߽磬�����i>=right,�ݹ���þͻ�������ԣ�����i<right, �ŵݹ���á�
           qsort(arr,i,right);
     if (j > left)      //��Ϊ������ĵݹ���ã�����leftΪ��߽磬jΪ�ұ߽磬�����j<=left,�ݹ���þͻ�������ԣ�����j>left���ŵݹ���á�
           qsort(arr,left,j);
}
