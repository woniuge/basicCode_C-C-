/*
	题目：
	输入2个集合，构成2个线性表LA,LB。
	合并LA,LB为新的线性表LC。
	要求：
	1. 上述操作分别采用顺序表和链表实现。
	2. 顺序表的定义及基本操作放在SQLIST.H中，链表的定义及基本操作放在LKLIST.H。
	3. 输入数据的个数及数据在主程序中完成。分别调用子程序完成顺序表和链表的的操作。
	4. 输入数据无序，LA,LB,LC递增有序。
	步骤：
	1. 建立SQLIST.H，其中包含顺序表的定义及基本操作。
	2. 建立LKLIST.H，其中包含链表的定义及基本操作。
	3. 在主函数中建立2个数组LA和LB。
	4. 在主函数中输入2个集合分别赋给LA与LB。
	5. 在主函数中选择实现方法。
	6. 在主函数中建立顺序（链）表LA_Sq（LA_Lk）和LB_Sq（LB_Lk）。
	6. 在主函数中调用函数Bubble_Sort分别对LA_Sq（LA_Lk）和LB_Sq（LB_Lk）进行排序。
	7. 在主函数中合并LA_Sq（LA_Lk）与LB_Sq（LB_Lk）为新的线性表LC。
*/

#include "SQLIST.H"			/* 包含顺序表的定义及基本操作 */
#include "LKLIST.H"			/* 包含链表的定义及基本操作 */

#define N 20

void fun_Sq(int LA[],int LB[],int n_LA,int n_LB);		/* 完成顺序表的相关操作 */
void fun_Lk(int LA[],int LB[],int n_LA,int n_LB);		/* 完成顺序表的相关操作 */
void Bubble_Sort(int s[],int n);
void Swap(int *px,int *py);

void ListSort(SqList *L);   /* 对L中的元素进行排序 */

int main(void)
{
	int i,n_LA,n_LB,choice;
	int LA[N],LB[N];

	/* 控制LA输入数据的个数 */
	do
	{
		printf("Enter n_LA(0<=n_LA<=%d):\n",N);
		scanf("%d",&n_LA);
	}while((n_LA<0)||(n_LA>N));

	/* 输入LA的数据 */
	printf("Input %d integer:\n",n_LA);
	for(i=0;i<n;i++)
		scanf("%d",&LA[i]);

	/* 控制LB输入数据的个数 */
	do
	{
		printf("Enter n_LB(0<=n_LB<=%d):\n",N);
		scanf("%d",&n_LB);
	}while((n_LB<0)||(n_LB>N));

	/* 输入LB的数据 */
	printf("Input %d integer:\n",n_LB);
	for(i=0;i<n;i++)
		scanf("%d",&LB[i]);

	/* 选择操作实现方法 */
	for(i=1;i<=3;i++)
	{
		/* 三行显示菜单 */
		printf("[1]: 顺序表实现方法 \n");
		printf("[2]: 链表实现方法 \n");
		printf("[0]: 退出 \n");

		/* 选择操作实现方法方法 */
		do
		{
			printf("Enter choice:\n");
			scanf("%d",&choice);
		}while((choice!=0)&&(choice!=1)&&(choice!=2));
		
		/* 根据输入的选项选择不同的排序方法 */
		switch(choice)
		{
		case 1:fun_Sq(LA,LB,n_LA,n_LB);break;
		case 2:fun_Lk(LA,LB,n_LA,n_LB);break;
		default:break;
		}

		printf("***************************************************\n");
	}
	
	return 0;
}

/* 完成顺序表的相关操作 */
void fun_Sq(int LA[],int LB[],int n_LA,int n_LB)
{
	SqList LA,LB,LC;
	
	InitList_Sq(SqList *LA)
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


/* 合并了Lb的La */
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

int main()
{
        
    SqList L;
	SqList Lb;
    
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

	//构造一个有10个数的Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L); 

    return 0;
}





/*  随机产生n个元素的值，建立带表头结点的单链线性表L（头插法） */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  先建立一个带头结点的单链表 */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand()%100+1;             /*  随机生成100以内的数字 */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  插入到表头 */
	}
}

/*  随机产生n个元素的值，建立带表头结点的单链线性表L（尾插法） */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* 初始化随机数种子 */
	*L = (LinkList)malloc(sizeof(Node)); /* L为整个线性表 */
	r=*L;                                /* r为指向尾部的结点 */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  生成新结点 */
		p->data = rand()%100+1;           /*  随机生成100以内的数字 */
		r->next=p;                        /* 将表尾终端结点的指针指向新结点 */
		r = p;                            /* 将当前的新结点定义为表尾终端结点 */
	}
	r->next = NULL;                       /* 表示当前链表结束 */
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L); 


    return 0;
}

