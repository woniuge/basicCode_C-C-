#include <stdio.h>
#include <stdlib.h>

/* **********************************************预定义常量和类型********************************************************* */

/* 函数结果状态代码 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

/* *******************************************顺序表的动态分配顺序存储结构************************************************ */

#define MAXSIZE 20		/* 存储空间初始分配量 */
#define LIST_INIT_SIZE 100	/* 线性表存储空间的初始分配量 */
#define LISTINCREMENT 10	/* 线性表存储空间的分配增量 */

typedef int Status;		/* Status是函数的类型，其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* 数据元素类型约定为ElemType，ElemType类型根据实际情况而定，这里假设为int */

/* 定义顺序表 */
typedef struct {
	ElemType *elem;		/* 存储空间基址 */
	ElemType data[LIST_INIT_SIZE];	/* 数组，存储数据元素 */
	int length;			/* 当前长度 */
	int listsize;		/* 当前分配的存储容量（以sizeof（ElemType）为单位） */
	int listincrement;	/* 约定的增补空间量（以sizeof（ElemType）为单位） */
}SqList;

/* *******************************************顺序表基本操作函数的声明************************************************ */

Status InitList_Sq(SqList *L);			/* 初始化顺序表,构造一个空线性表L */

Status DestroyList_Sq(SqList *L);		/* 在线性表L存在的情况下，摧毁线性表L */

Status ClearList_Sq(SqList *L);		/* 在线性表L存在的条件下，将L重置为空表 */

Status ListEmpty_Sq(SqList L);			/* 在线性表L存在的条件下，判断L是否为空，若L为空返回TRUE，否则返回FLASE */

int ListLength_Sq(SqList L);			/* 在线性表L存在的条件下，返回表中元素的个数 */

Status GetElem_Sq(SqList L,int i,ElemType *e);/* 在1≤i≤ListLength(L)条件下,用e返回L中第i个元素,其中i指位置,第1个位置的数组是从0开始 */

int LocateElem_Sq(SqList L,ElemType e);/* 返回L中第一个与e满足相等关系的元素的位序,如不存在，返回0 */

Status ListInsert_Sq(SqList *L,int i,ElemType e);/* 在1≤i≤ListLength(L)+1条件下,在L中第i个位置之前插入新的数据元素e,L的长度加1。*/

Status ListDelete_Sq(SqList *L,int i,ElemType *e);/* 在1≤i≤ ListLength(L)条件下，删除L的第i个数据元素，并用e返回其值，L的长度减1。*/

Status ListTraverse_Sq(SqList L);/* 依次输出L中的每个数据元素。 */




/* *******************************************顺序表基本操作函数的定义************************************************ */

/* 1.操作结果：构造一个空的顺序表L。 */
Status InitList_Sq(SqList *L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE* sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);		/* 存储分配失败 */
	L.length = 0;					/* 空表长度为0 */
	L.listsize = LIST_INIT_SIZE;	/* 初始存储容量 */

	return OK;
}

/* 2.初始条件：顺序线性表L已存在。
	 操作结果：销毁线性表L */
Status DestroyList_Sq(SqList *L)
{
	delete []L.data;
	L.length=0;
	L.listsize=0;

}

/* 3.初始条件：顺序线性表L已存在。
	 操作结果：将L重置为空表 */
Status ClearList_Sq(SqList *L)
{ 
    L.length=0;
    return OK;
}
		
/* 4.初始条件：顺序线性表L已存在。
	 操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty_Sq(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* 5.初始条件：顺序线性表L已存在。
	 操作结果：返回L中数据元素个数 */
int ListLength_Sq(SqList L)
{
	return L.length;
}

/* 6.初始条件：顺序线性表L已存在，1≤i≤ListLength(L)。
	 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
Status GetElem_Sq(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
            return ERROR;
    *e=L.data[i-1];

    return OK;
}

/* 7.初始条件：顺序线性表L已存在
	 操作结果：返回L中第1个与e满足相等关系的数据元素的位序。若这样的数据元素不存在，则返回值为0。 */
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

/* 8.初始条件：顺序线性表L已存在,1≤i≤ListLength(L)+1。
	 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1。 */
Status ListInsert_Sq(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L.length==LIST_INIT_SIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>L.length+1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i<=L.length)        /* 若插入数据位置不在表尾 */
	{
		for(k=L.length-1;k>=i-1;k--)  /* 将要插入位置之后的数据元素向后移动一位 */
			L.data[k+1]=L.data[k];
	}
	L.data[i-1]=e;          /* 将新元素插入 */
	L.length++;

	return OK;
}

/* 9.初始条件：顺序线性表L已存在且非空，1≤i≤ListLength(L)。
	 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete_Sq(SqList *L,int i,ElemType *e) 
{ 
    int k;
    if (L.length==0)               /* 线性表为空 */
		return ERROR;
    if (i<1 || i>L.length)         /* 删除位置不正确 */
        return ERROR;
    *e=L.data[i-1];
    if (i<L.length)                /* 如果删除不是最后位置 */
    {
        for(k=i;k<L.length;k++)/* 将删除位置后继元素前移 */
			L.data[k-1]=L.data[k];
    }
    L.length--;
    return OK;
}

/* 10.初始条件：顺序线性表L已存在
	  操作结果：依次对L的每个数据元素输出 */
Status ListTraverse_Sq(SqList L)
{
	int i,first=1;
    for(i=0;i<L.length;i++)
	{
		if(first)
		{
			printf("%d",L.data[i]);
			first=0;
		}
		else
			printf(" %d",L.data[i]);
	}
    printf("\n");

    return OK;
}