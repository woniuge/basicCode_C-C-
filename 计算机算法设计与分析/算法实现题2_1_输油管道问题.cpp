//算法实现题2_1_输油管道问题


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
	FILE * fp1, * fp2;			//定义文件指针
	struct point a[M];			//定义存储各点坐标的结构数组
	int n;						//定义油井数
	int b[M];					//定义存储油井位置坐标的纵坐标
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




void swap(int *a, int *b)        //swap()函数实现交换两个数组元素的值的功能。
{ 
  int t;
  t = *a; 
  *a = *b; 
  *b = t; 
}

void qsort(int arr[],int left,int right)    
{                                      
	 int i = left;                   //用i从左边开始扫描数组。         
     int j = right;                  //用j从右边开始扫描数组。
     
	 int key = arr[(i+j)/2];             //先设置一个基准值key，此程序是以数组的中间位置的元素为基准值。
 
	 while(i < j)         //因为，若i>=j时，i所指向的数组元素，都是j已经访问，判断过的元素，不用再用i去访问，判断了。                    
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
     if (i < right)     //因为，下面的递归调用，是以i为左边界，right为右边界，如果，i>=right,递归调用就会出错，所以，必须i<right, 才递归调用。
           qsort(arr,i,right);
     if (j > left)      //因为，下面的递归调用，是以left为左边界，j为右边界，如果，j<=left,递归调用就会出错，所以，必须j>left，才递归调用。
           qsort(arr,left,j);
}
