

#include "LKLIST.H"		/* 包含链表的定义及基本操作 */

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
