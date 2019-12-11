
#include <stdio.h>    
#include <stdlib.h>   

/* **********************************************预定义常量和类型********************************************************* */

/* 函数结果状态代码 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;          /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;        /* ElemType类型根据实际情况而定，这里假设为int */

/* *******************************************顺序表的动态分配顺序存储结构************************************************ */

/* 顺序表的存储结构定义 */
typedef struct
{
	ElemType data[MAXSIZE];        /* 数组，存储数据元素 */
	int length;                     /* 线性表当前长度 */
}SqList;

/* *******************************************顺序表基本操作函数的定义************************************************ */

/* 初始化顺序线性表 */
Status InitList(SqList *L) 
{ 
    L->length=0;			/* 写为(*L).length=0也可以，以下雷同 */
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L,ElemType e)
{
    int i;
    if (L.length==0)
            return 0;
    for(i=0;i<L.length;i++)
    {
            if (L.data[i]==e)
                    break;
    }
    if(i>=L.length)
            return 0;

    return i+1;
}


/* 初始条件：顺序线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>L->length+1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i<=L->length)        /* 若插入数据位置不在表尾 */
	{
		for(k=L->length-1;k>=i-1;k--)  /* 将要插入位置之后的数据元素向后移动一位 */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          /* 将新元素插入 */
	L->length++;

	return OK;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList *L,int i,ElemType *e) 
{ 
    int k;
    if (L->length==0)               /* 线性表为空 */
		return ERROR;
    if (i<1 || i>L->length)         /* 删除位置不正确 */
        return ERROR;
    *e=L->data[i-1];
    if (i<L->length)                /* 如果删除不是最后位置 */
    {
        for(k=i;k<L->length;k++)/* 将删除位置后继元素前移 */
			L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
	int i;

    for(i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
    printf("\n");

    return OK;
}

void unionL(SqList *La,SqList Lb);	/* 将所有在顺序表Lb中但不在La中的数据元素插入到La中 */
void Bubble_Sort(SqList *L);	/* 对顺序表L中的数据元素进行排序 */
void Swap(int *px,int *py);	/* 交换指针px和py所指向的数据 */

/* 已知顺序表La和Lb的元素按值非递减排列
   归并La和Lb得到新的顺序表Lc，Lc的元素也按值非递减排列 */
void MergeList(SqList La,SqList Lb,SqList *Lc);	

int main()
{
        
    SqList L;
	SqList Lb;
	SqList Lc;
	SqList Ld;
    
    ElemType e;
    Status i;
    int j,k;

    i=InitList(&L);
    printf("1#:初始化L后：L.length=%d,i=%d\n",L.length,i);
	printf("*******************************************************************************\n");

    for(j=1;j<=5;j++)
		ListInsert(&L,1,j);		/* 采用尾插法 */
    printf("\n2#:在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);
	printf("*******************************************************************************\n");

    printf("\n3#:L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("  L是否空：i=%d(1:是 0:否)\n",i);
	printf("*******************************************************************************\n");

    i=ClearList(&L);
    printf("\n4#:清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("  L是否空：i=%d(1:是 0:否)\n",i);
	printf("*******************************************************************************\n");

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);		/* 采用头插法 */
    printf("\n5#:在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 
	printf("  L.length=%d \n",L.length);
	printf("*******************************************************************************\n");

    ListInsert(&L,1,0);
    printf("\n6#:在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("  L.length=%d \n",L.length);
	printf("*******************************************************************************\n");

    GetElem(L,5,&e);
    printf("\n7#:第5个元素的值为：%d\n",e);

    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("  第%d个元素的值为：%d\n",k,j);
            else
                    printf("  没有值为%d的元素\n",j);
    }
	printf("*******************************************************************************\n");

    k=ListLength(L); /* k为表长 */
	printf("\n8#:L的表长为：%d\n",k);
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("  删除第%d个数据失败\n",j);
            else
                    printf("  删除第%d个的元素值为：%d\n",j,e);
    }
    printf("  依次输出L的元素：");
    ListTraverse(L); 
	printf("*******************************************************************************\n");

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("\n9#:删除第%d个的元素值为：%d\n",j,e);
    printf("  依次输出L的元素：");
    ListTraverse(L); 
	printf("*******************************************************************************\n");

	/* 构造一个有10个数的Lb */
	InitList(&Lb);
    for(j=6;j<=15;j++)
		ListInsert(&Lb,1,j);
	printf("\n10#:依次输出Lb的元素：");
	ListTraverse(Lb);
	unionL(&L,Lb);
	printf("  依次输出合并了Lb的L的元素：");
    ListTraverse(L); 
	printf("*******************************************************************************\n");

	int n;
	InitList(&Lc);
	printf("\n11#:请输入Lc中元素的个数n：");
	scanf("%d",&n);
	printf("  请输入Lc中的元素：");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		ListInsert(&Lc,1,e);	/* 采用头插法 */
	}
	printf("  依次输出排序之前的Lc的元素：");
	ListTraverse(Lc);
	Bubble_Sort(&Lc);
	printf("  依次输出排序之后的Lc的元素：");
	ListTraverse(Lc);
	printf("*******************************************************************************\n");

	printf("\n12#：依次输出排序之前的Lb中的元素：");
	ListTraverse(Lb);
	Bubble_Sort(&Lb);
	printf("  依次输出排序之后的Lb中的元素：");
	ListTraverse(Lb);
	printf("  依次输出排序之后的Lc的元素：");
	ListTraverse(Lc);
	MergeList(Lb,Lc,&Ld);
	printf("  依次输出由归并Lb和Lc得到的Ld中的元素：");
	ListTraverse(Ld);
	printf("*******************************************************************************\n");

    return 0;
}

/* 将所有在顺序表Lb中但不在La中的数据元素插入到La中 */
void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;

	La_len=ListLength(*La);
	Lb_len=ListLength(Lb);

	for (i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);
		if (!LocateElem(*La,e))
			ListInsert(La,++La_len,e);
	}
}

/* 对顺序表L中的数据元素进行排序 */
void Bubble_Sort(SqList *L)
{
	int i,j;

	for(i=1;i<L->length;i++)
		for(j=0;j< L->length-i;j++)
			if(L->data[j] > L->data[j+1])
				Swap(&L->data[j],&L->data[j+1]);
}

/* 交换指针px和py所指向的数据 */
void Swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}

/* 已知顺序表La和Lb的元素按值非递减排列
   归并La和Lb得到新的顺序表Lc，Lc的元素也按值非递减排列 */
void MergeList(SqList La,SqList Lb,SqList *Lc)
{
	int i,j,k=0;      

	InitList(Lc);
	i=j=1;
	La.length = ListLength(La);
	Lb.length = ListLength(Lb);
	while((i<=La.length) && (j<=Lb.length))	/* La与Lb均非空 */
	{
		GetElem(La, i, &La.data[i-1]);
		GetElem(Lb, j, &Lb.data[j-1]);
		if(La.data[i-1] < Lb.data[j-1])
		{
			ListInsert(Lc,++k, La.data[i-1]);
			++i;
		}
		else
			if(La.data[i-1] > Lb.data[j-1])
			{
				ListInsert(Lc,++k, Lb.data[j-1]);
				++j;
			}
			else
			{
				ListInsert(Lc,++k, La.data[i-1]);
				++i;
				++j;
			}
	}
	while(i <= La.length)	
	{
		GetElem(La,i, &La.data[i-1]);
		ListInsert(Lc,++k, La.data[i-1]);
		i++;
	}
	while(j <= Lb.length)
	{
		GetElem(Lb,j, &Lb.data[j-1]);
		ListInsert(Lc,++k, Lb.data[j-1]);
		j++;
	}

}