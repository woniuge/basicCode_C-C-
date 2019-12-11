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

/* *******************************************单向链表的动态分配顺序存储结构************************************************ */

#define MAXSIZE 20		/* 存储空间初始分配量 */
#define LIST_INIT_SIZE 100	/* 线性表存储空间的初始分配量 */
#define LISTINCREMENT 10	/* 线性表存储空间的分配增量 */

typedef int Status;		/* Status是函数的类型，其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* 数据元素类型约定为ElemType，ElemType类型根据实际情况而定，这里假设为int */

/* 定义带头结点的单向链表存储结构 */
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node,*LinkList; /* 定义LinkList */

/* *******************************************单向链表基本操作函数的声明************************************************ */

Status InitList_Lk(LinkList *L);		/* 初始化链式顺序表,构造一个空链式线性表L */

Status DestroyList_Lk(LinkList *L);		/* 在链式线性表L存在的情况下，摧毁链式线性表L */

Status ClearList_Lk(LinkList *L);		/* 在链式线性表L存在的条件下，将L重置为空表 */

Status ListEmpty_Lk(LinkList L);		/* 在链式线性表L存在的条件下，判断L是否为空，若L为空返回TRUE，否则返回FLASE */

int ListLength_Lk(LinkList L);			/* 在链式线性表L存在的条件下，返回表中元素的个数 */

Status GetElem_Lk(LinkList L,int i,ElemType *e);/* 在1≤i≤ListLength(L)条件下,用e返回L中第i个元素的值 */

int LocateElem_Lk(LinkList L,ElemType e);/* 返回L中第一个与e满足相等关系的元素的位序,如不存在，返回0 */

Status ListInsert_Lk(LinkList *L,int i,ElemType e);/* 在1≤i≤ListLength(L)+1条件下,在L中第i个位置之前插入新的数据元素e,L的长度加1。*/

Status ListDelete_Lk(LinkList *L,int i,ElemType *e);/* 在1≤i≤ ListLength(L)条件下，删除L的第i个数据元素，并用e返回其值，L的长度减1。*/

Status ListTraverse_Lk(LinkList L);/* 依次输出L中的每个数据元素。 */



/* *******************************************单向链表基本操作函数的定义************************************************ */

/* 1.初始化链式线性表 */
Status InitList_Lk(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L))    /* 存储分配失败 */
            return ERROR;
    (*L)->next=NULL; /* 指针域为空 */

    return OK;
}

/* 2.初始条件：链式线性表L已存在。
	 操作结果：销毁线性表L */
Status DestroyList_Lk(LinkList *L)
{
	/*delete []L.data;
	L.length=0;
	L.listsize=0;*/

}

/* 3.初始条件：链式线性表L已存在。操作结果：将L重置为空表 */
Status ClearList_Lk(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  p指向第一个结点 */
	while(p)                /*  没到表尾 */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* 头结点指针域为空 */
	return OK;
}

/* 4.初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty_Lk(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* 5.初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength_Lk(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向第一个结点 */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* 6.初始条件：链式线性表L已存在，1≤i≤ListLength(L)
     操作结果：用e返回L中第i个数据元素的值
	 L为带头结点的单链表的头指针
	 当第i个元素存在时，将其值赋给e并返回OK，否则返回ERROR */
Status GetElem_Lk(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* 声明一结点p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */

	while (p && j<i)  /* p不为空并且计数器j还没有等于i时，循环继续 */
	{   
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */

	return OK;
}

/* 7.初始条件：链式线性表L已存在
     操作结果：返回L中第1个与e满足关系的数据元素的位序。若这样的数据元素不存在，则返回值为0 */
int LocateElem_Lk(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* 找到这样的数据元素 */
                return i;
        p=p->next;
    }

    return 0;
}


/* 8.初始条件：带头结点的单链线性表L已存在,1≤i≤ListLength(L)。
     操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert_Lk(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 0;
	while (p && j < i-1)     /* 寻找第i-1个结点 */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i-1)	/* i小于1或者大于表长+1 */
		return ERROR;   /* 第i个位置不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;  
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

/* 9.初始条件：带头结点的单链式线性表L已存在，1≤i≤ListLength(L)。
     操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete_Lk(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 0;
	while (p->next && j < i-1)	/* 遍历寻找第i个结点，并令p指向其前趋 */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i-1) 
	    return ERROR;           /* 删除位置不合理，第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}

/* 10.初始条件：链式线性表L已存在。 
      操作结果：依次对L的每个数据元素输出 */
Status ListTraverse_Lk(LinkList L)
{
	int first=1;

    LinkList p=L->next;
    while(p)
    {
		if(first)
		{
			printf("%d",p.data);
			first=0;
		}
		else
			printf(" %d",p.data);
        p=p.next;
    }
    printf("\n");
    return OK;
}