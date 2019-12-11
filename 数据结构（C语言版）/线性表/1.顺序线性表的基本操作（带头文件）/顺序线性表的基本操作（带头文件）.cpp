
#include "SQLIST.H"	/* 顺序表的基本操作及定义 */

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