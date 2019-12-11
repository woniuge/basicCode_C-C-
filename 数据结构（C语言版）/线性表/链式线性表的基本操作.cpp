
#include <stdio.h>     
#include <stdlib.h>   

/* **********************************************预定义常量和类型********************************************************* */

/* 函数结果状态代码 */
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType是数据元素的类型，根据实际情况而定，这里假设为int */

/* *******************************************单向链表的动态分配顺序的存储结构************************************************ */

/* 定义带头结点的链式线性表的存储结构 */
typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList */

/* *******************************************单向链表基本操作函数的定义************************************************ */

/* 输出数据元素c */
Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* 初始化链式线性表 */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L)) /* 存储分配失败 */
            return ERROR;
    (*L)->next=NULL; /* 指针域为空 */

    return OK;
}

/* 初始条件：链式线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* 初始条件：链式线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(LinkList *L)
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

/* 初始条件：链式线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
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

/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* 声明一结点指针p */
	p = L->next;		/* 让p指向链表L的第一个结点 */
	j = 1;		/*  j为计数器 */
	while (p && j<i)  /* p不为空或者计数器j还没有等于i时，循环继续 */
	{   
		p = p->next;  /* 让p指向下一个结点 */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  第i个元素不存在 */
	*e = p->data;   /*  取第i个元素的数据 */
	return OK;
}

/* 初始条件：链式线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(LinkList L,ElemType e)
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


/* 初始条件：链式线性表L已存在,1≤i≤ListLength(L)， */
/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     /* 寻找第i个结点 */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   /* 第i个元素不存在 */
	s = (LinkList)malloc(sizeof(Node));  /*  生成新结点(C语言标准函数) */
	s->data = e;  
	s->next = p->next;      /* 将p的后继结点赋值给s的后继  */
	p->next = s;          /* 将s赋值给p的后继 */
	return OK;
}

/* 初始条件：链式线性表L已存在，1≤i≤ListLength(L) */
/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* 遍历寻找第i个元素 */
	{
        p = p->next;
        ++j;
	}
	if (!(p->next) || j > i) 
	    return ERROR;           /* 第i个元素不存在 */
	q = p->next;
	p->next = q->next;			/* 将q的后继赋值给p的后继 */
	*e = q->data;               /* 将q结点中的数据赋给e */
	free(q);                    /* 让系统回收此结点，释放内存 */
	return OK;
}

/* 初始条件：链式线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}


void unionL(LinkList *La,LinkList Lb);	/* 将所有在链式线性表Lb中但不在La中的数据元素插入到La中 */
void Bubble_Sort(LinkList *L);	/* 对链式线性表L中的数据元素进行排序 */
void Swap(int *px,int *py);	/* 交换指针px和py所指向的数据 */

/* 已知链式线性表La和Lb的元素按值非递减排列
   归并La和Lb得到新的链式线性表Lc，Lc的元素也按值非递减排列 */
void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc);	


int main()
{        
    LinkList L;
	LinkList La;
	LinkList Lb;
	LinkList Lc;

    ElemType e;
    Status i;
    int j,k;

    i=InitList(&L);
    printf("#1：初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
		ListInsert(&L,1,j);			/* 头插法 */
    printf("  在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("  ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("  L是否空：i=%d(1:是 0:否)\n",i);

	printf("*******************************************************************************\n");

    i=ClearList(&L);
    printf("\n#2:清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("  L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
		ListInsert(&L,j,j);		/* 尾插法 */
    printf("  在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("  ListLength(L)=%d \n",ListLength(L));

	printf("*******************************************************************************\n");

    ListInsert(&L,1,0);
    printf("\n#3:在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("  ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("  第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("  第%d个元素的值为%d\n",k,j);
            else
                    printf("  没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
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

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("  删除第%d个的元素值为：%d\n",j,e);

    printf("  依次输出L的元素：");
    ListTraverse(L); 

	printf("*******************************************************************************\n");

    i=ClearList(&L);
    printf("\n#4:清空L后：ListLength(L)=%d\n",ListLength(L));
	int n;
	printf("  输入L中的数据个数n：");
	scanf("%d",&n);
	printf("  输入L中的元素:");
	for(j=1;j<=n;j++)
	{
		scanf("%d",&e);
		ListInsert(&L,j,e);
	}
	printf("  依次输出L中的元素：");
	ListTraverse(L);

	InitList(&La);
	for(j=1;j<=5;j++)
		ListInsert(&La,j,j);
	printf("  依次输出La中的元素：");
	ListTraverse(La);
	unionL(&L,La);
	printf("  依次输出合并了La之后的L中的元素：");
	ListTraverse(L);

	Bubble_Sort(&L);
	printf("  依次输出排序之后的L的元素：");
	ListTraverse(L);

	printf("*******************************************************************************\n");

	int m;
	InitList(&Lb);
	printf("\n#5:输入Lb中的数据个数m：");
	scanf("%d",&m);
	printf("  输入Lb中的元素:");
	for(j=1;j<=m;j++)
	{
		scanf("%d",&e);
		ListInsert(&Lb,j,e);
	}
	printf("  依次输出Lb中的元素：");
	ListTraverse(Lb);
	Bubble_Sort(&Lb);
	printf("  依次输出排序之后的Lb的元素：");
	ListTraverse(Lb);

	InitList(&Lc);
	MergeList(&L,&Lb,&Lc);
	printf("  依次输出由L与Lb归并得到的Lc的元素：");
	ListTraverse(Lc);

    return 0;
}


/* 将所有在链式线性表Lb中但不在La中的数据元素插入到La中 */
void unionL(LinkList *La,LinkList Lb)
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

/* 对链式线性表L中的数据元素进行排序 */
void Bubble_Sort(LinkList *L)
{
	int i,j;
	int length;
	LinkList p;

	length=ListLength(*L);
	for(i=1;i < length;i++)
	{
		p=(*L)->next;
		for(j=0;j< length-i;j++)
		{
			if(j>0)
				p=p->next;
			if(p->data > p->next->data)
				Swap(&(p->data) , &(p->next->data));
		}
	}
}

/* 交换指针px和py所指向的数据 */
void Swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}

/* 已知链式线性表La和Lb的元素按值非递减排列
   归并La和Lb得到新的链式线性表Lc，Lc的元素也按值非递减排列 */
void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc)
{
	LinkList pa,pb,pc;

	pa = (*La)->next;
	pb = (*Lb)->next;
	*Lc = *La;		/* 用La的头结点作为Lc的头结点 */
	pc = *Lc;

	while(pa && pb)	/* La与Lb均非空 */
	{
		if(pa->data < pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
			if(pa->data > pb->data)
			{
				pc->next = pb;
				pc = pb;
				pb = pb->next;
			}
			else
				{
					pc->next = pa;
					pc = pa;
					pa = pa->next;
					pb = pb->next;
				}
	}
	pc->next = pa ? pa : pb;	/* 插入剩余段 */
}
