/* 
题目：
	在一个工程内实现冒泡排序和选择排序。
要求：
	1. 每种排序方法由不同的子程序实现。
	2. 输出每一趟排序的结果，仔细观察输出结果。
	3. 输入数据的个数及数据在主程序中完成。
步骤：
	1. 主函数负责数据输入与排序方法的选择。
	2. 子函数一负责冒泡排序。
	3. 子函数二负责选择排序。
	4. 子函数三负责交换。
	4. 子函数四负责输出每一趟排序的结果。
 */
#include <stdio.h>
#define N 20

void Bubble_Sort(int s[],int n);
void Selection_Sort(int s[],int n);
void Swap(int *,int *);
void Result(int s[],int n);

int main(void)
{
	int i,n,choice;
	int s[N];

	/* 控制输入数据的个数 */
	do
	{
		printf("Enter n(0<=n<=%d):\n",N);
		scanf("%d",&n);
	}while((n<0)||(n>N));

	/* 输入数据 */
	printf("Input %d integer:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);

	for(i=1;i<=3;i++)
	{
		/* 三行显示菜单 *//* 选择排序方法 */
		printf("[1]: Select Bubble Sort \n");
		printf("[2]: Select Selection Sort \n");
		printf("[0]: exit \n");

		/* 选择排序方法 */
		do
		{
			printf("Enter choice:\n");
			scanf("%d",&choice);
		}while((choice!=0)&&(choice!=1)&&(choice!=2));

		if(choice==0)
			break;
		
		/* 根据输入的选项选择不同的排序方法 */
		switch(choice)
		{
		case 1:Bubble_Sort(s,n);break;
		case 2:Selection_Sort(s,n);break;
		}

		printf("***************************************************\n");
	}

	return 0;
}

/* 冒泡排序 */
void Bubble_Sort(int s[],int n)
{
	int i,j,count=1;
	int a[N];

	for(i=0;i<n;i++)
		a[i]=s[i];

	for(i=1;i<n;i++)
		for(j=0;j<n-i;j++)
		{
			if(a[j]>a[j+1])
				Swap(&a[j],&a[j+1]);
			printf("#%3d:",count);
			count++;
			Result(a,n);
		}
}

/* 选择排序 */
void Selection_Sort(int s[],int n)
{
	int i,j,index,count=1;
	int b[N];

	for(i=0;i<n;i++)
		b[i]=s[i];

	for(i=0;i<n-1;i++)
	{
		index=i;
		for(j=i+1;j<n;j++)
		{
			if(b[j]<b[index])
				index=j;
			Swap(&b[i],&b[index]);
			printf("#%3d:",count);
			count++;
			Result(b,n);
		}
	}
}

/* 交换 */
void Swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}

/* 输出每一趟排序的结果 */
void Result(int s[],int n)
{
	int i,first=1;

	for(i=0;i<n;i++)
	{
		if(first)
		{
			first=0;
			printf("%2d",s[i]);
		}
		else
			printf(" %2d",s[i]);
	}
	printf("\n");
}
