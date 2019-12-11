
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
Status InitList_Sq(SqList *L) 
{ 
    L->length=0;			/* 写为(*L).length=0也可以，以下雷同 */
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty_Sq(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList_Sq(SqList *L)
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength_Sq(SqList L)
{
	return L.length;
}

/* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem_Sq(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
		return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem_Sq(SqList L,ElemType e)
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
Status ListInsert_Sq(SqList *L,int i,ElemType e)
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
Status ListDelete_Sq(SqList *L,int i,ElemType *e) 
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
Status ListTraverse_Sq(SqList L)
{
	int i;

    for(i=0;i<L.length;i++)
		printf("%d ",L.data[i]);
    printf("\n");

    return OK;
}


/* 将所有在顺序表Lb中但不在La中的数据元素插入到La中 */
void unionL_Sq(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;

	La_len=ListLength_Sq(*La);
	Lb_len=ListLength_Sq(Lb);

	for (i=1;i<=Lb_len;i++)
	{
		GetElem_Sq(Lb,i,&e);
		if (!LocateElem_Sq(*La,e))
			ListInsert_Sq(La,++La_len,e);
	}
}

/* 交换指针px和py所指向的数据 */
void Swap_Sq(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}

/* 对顺序表L中的数据元素进行排序 */
void Bubble_Sort_Sq(SqList *L)
{
	int i,j;

	for(i=1;i<L->length;i++)
		for(j=0;j< L->length-i;j++)
			if(L->data[j] > L->data[j+1])
				Swap_Sq(&L->data[j],&L->data[j+1]);
}

/* 已知顺序表La和Lb的元素按值非递减排列
   归并La和Lb得到新的顺序表Lc，Lc的元素也按值非递减排列 */
void MergeList_Sq(SqList La,SqList Lb,SqList *Lc)
{
	int i,j,k=0;      

	InitList_Sq(Lc);
	i=j=1;
	La.length = ListLength_Sq(La);
	Lb.length = ListLength_Sq(Lb);
	while((i<=La.length) && (j<=Lb.length))	/* La与Lb均非空 */
	{
		GetElem_Sq(La, i, &La.data[i-1]);
		GetElem_Sq(Lb, j, &Lb.data[j-1]);
		if(La.data[i-1] < Lb.data[j-1])
		{
			ListInsert_Sq(Lc,++k, La.data[i-1]);
			++i;
		}
		else
			if(La.data[i-1] > Lb.data[j-1])
			{
				ListInsert_Sq(Lc,++k, Lb.data[j-1]);
				++j;
			}
			else
			{
				ListInsert_Sq(Lc,++k, La.data[i-1]);
				++i;
				++j;
			}
	}
	while(i <= La.length)	
	{
		GetElem_Sq(La,i, &La.data[i-1]);
		ListInsert_Sq(Lc,++k, La.data[i-1]);
		i++;
	}
	while(j <= Lb.length)
	{
		GetElem_Sq(Lb,j, &Lb.data[j-1]);
		ListInsert_Sq(Lc,++k, Lb.data[j-1]);
		j++;
	}
}