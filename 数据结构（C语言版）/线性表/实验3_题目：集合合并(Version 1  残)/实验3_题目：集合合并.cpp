/*
	��Ŀ��
	����2�����ϣ�����2�����Ա�LA,LB��
	�ϲ�LA,LBΪ�µ����Ա�LC��
	Ҫ��
	1. ���������ֱ����˳��������ʵ�֡�
	2. ˳���Ķ��弰������������SQLIST.H�У�����Ķ��弰������������LKLIST.H��
	3. �������ݵĸ���������������������ɡ��ֱ�����ӳ������˳��������ĵĲ�����
	4. ������������LA,LB,LC��������
	���裺
	1. ����SQLIST.H�����а���˳���Ķ��弰����������
	2. ����LKLIST.H�����а�������Ķ��弰����������
	3. ���������н���2������LA��LB��
	4. ��������������2�����Ϸֱ𸳸�LA��LB��
	5. ����������ѡ��ʵ�ַ�����
	6. ���������н���˳��������LA_Sq��LA_Lk����LB_Sq��LB_Lk����
	6. ���������е��ú���Bubble_Sort�ֱ��LA_Sq��LA_Lk����LB_Sq��LB_Lk����������
	7. ���������кϲ�LA_Sq��LA_Lk����LB_Sq��LB_Lk��Ϊ�µ����Ա�LC��
*/

#include "SQLIST.H"			/* ����˳���Ķ��弰�������� */
#include "LKLIST.H"			/* ��������Ķ��弰�������� */

#define N 20

void fun_Sq(int LA[],int LB[],int n_LA,int n_LB);		/* ���˳������ز��� */
void fun_Lk(int LA[],int LB[],int n_LA,int n_LB);		/* ���˳������ز��� */
void Bubble_Sort(int s[],int n);
void Swap(int *px,int *py);

void ListSort(SqList *L);   /* ��L�е�Ԫ�ؽ������� */

int main(void)
{
	int i,n_LA,n_LB,choice;
	int LA[N],LB[N];

	/* ����LA�������ݵĸ��� */
	do
	{
		printf("Enter n_LA(0<=n_LA<=%d):\n",N);
		scanf("%d",&n_LA);
	}while((n_LA<0)||(n_LA>N));

	/* ����LA������ */
	printf("Input %d integer:\n",n_LA);
	for(i=0;i<n;i++)
		scanf("%d",&LA[i]);

	/* ����LB�������ݵĸ��� */
	do
	{
		printf("Enter n_LB(0<=n_LB<=%d):\n",N);
		scanf("%d",&n_LB);
	}while((n_LB<0)||(n_LB>N));

	/* ����LB������ */
	printf("Input %d integer:\n",n_LB);
	for(i=0;i<n;i++)
		scanf("%d",&LB[i]);

	/* ѡ�����ʵ�ַ��� */
	for(i=1;i<=3;i++)
	{
		/* ������ʾ�˵� */
		printf("[1]: ˳���ʵ�ַ��� \n");
		printf("[2]: ����ʵ�ַ��� \n");
		printf("[0]: �˳� \n");

		/* ѡ�����ʵ�ַ������� */
		do
		{
			printf("Enter choice:\n");
			scanf("%d",&choice);
		}while((choice!=0)&&(choice!=1)&&(choice!=2));
		
		/* ���������ѡ��ѡ��ͬ�����򷽷� */
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

/* ���˳������ز��� */
void fun_Sq(int LA[],int LB[],int n_LA,int n_LB)
{
	SqList LA,LB,LC;
	
	InitList_Sq(SqList *LA)
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


/* �ϲ���Lb��La */
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
    printf("��ʼ��L��L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    i=ClearList(&L);
    printf("���L��L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    

    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ɾ����j������ */
            if(i==ERROR)
                    printf("ɾ����%d������ʧ��\n",j);
            else
                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);

    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

	//����һ����10������Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("��������ϲ���Lb��L��Ԫ�أ�");
    ListTraverse(L); 

    return 0;
}





/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /*  �Ƚ���һ����ͷ���ĵ����� */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand()%100+1;             /*  �������100���ڵ����� */
		p->next = (*L)->next;    
		(*L)->next = p;						/*  ���뵽��ͷ */
	}
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                      /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node)); /* LΪ�������Ա� */
	r=*L;                                /* rΪָ��β���Ľ�� */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); /*  �����½�� */
		p->data = rand()%100+1;           /*  �������100���ڵ����� */
		r->next=p;                        /* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            /* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       /* ��ʾ��ǰ������� */
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("��ʼ��L��ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    i=ClearList(&L);
    printf("���L��ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("û��ֵΪ%d��Ԫ��\n",j);
    }
    

    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ɾ����j������ */
            if(i==ERROR)
                    printf("ɾ����%d������ʧ��\n",j);
            else
                    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);

    printf("�������L��Ԫ�أ�");
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n���L��ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("���崴��L��Ԫ��(ͷ�巨)��");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\nɾ��L��ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("���崴��L��Ԫ��(β�巨)��");
    ListTraverse(L); 


    return 0;
}

