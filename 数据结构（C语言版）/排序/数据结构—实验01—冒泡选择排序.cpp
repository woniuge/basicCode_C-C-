/* 
��Ŀ��
	��һ��������ʵ��ð�������ѡ������
Ҫ��
	1. ÿ�����򷽷��ɲ�ͬ���ӳ���ʵ�֡�
	2. ���ÿһ������Ľ������ϸ�۲���������
	3. �������ݵĸ���������������������ɡ�
���裺
	1. �����������������������򷽷���ѡ��
	2. �Ӻ���һ����ð������
	3. �Ӻ���������ѡ������
	4. �Ӻ��������𽻻���
	4. �Ӻ����ĸ������ÿһ������Ľ����
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

	/* �����������ݵĸ��� */
	do
	{
		printf("Enter n(0<=n<=%d):\n",N);
		scanf("%d",&n);
	}while((n<0)||(n>N));

	/* �������� */
	printf("Input %d integer:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&s[i]);

	for(i=1;i<=3;i++)
	{
		/* ������ʾ�˵� *//* ѡ�����򷽷� */
		printf("[1]: Select Bubble Sort \n");
		printf("[2]: Select Selection Sort \n");
		printf("[0]: exit \n");

		/* ѡ�����򷽷� */
		do
		{
			printf("Enter choice:\n");
			scanf("%d",&choice);
		}while((choice!=0)&&(choice!=1)&&(choice!=2));

		if(choice==0)
			break;
		
		/* ���������ѡ��ѡ��ͬ�����򷽷� */
		switch(choice)
		{
		case 1:Bubble_Sort(s,n);break;
		case 2:Selection_Sort(s,n);break;
		}

		printf("***************************************************\n");
	}

	return 0;
}

/* ð������ */
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

/* ѡ������ */
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

/* ���� */
void Swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}

/* ���ÿһ������Ľ�� */
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
