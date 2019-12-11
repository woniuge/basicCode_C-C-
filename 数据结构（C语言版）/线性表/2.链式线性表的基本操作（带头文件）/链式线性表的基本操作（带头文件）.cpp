

#include "LKLIST.H"		/* ��������Ķ��弰�������� */

void unionL(LinkList *La,LinkList Lb);	/* ����������ʽ���Ա�Lb�е�����La�е�����Ԫ�ز��뵽La�� */
void Bubble_Sort(LinkList *L);	/* ����ʽ���Ա�L�е�����Ԫ�ؽ������� */
void Swap(int *px,int *py);	/* ����ָ��px��py��ָ������� */

/* ��֪��ʽ���Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
   �鲢La��Lb�õ��µ���ʽ���Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
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
    printf("#1����ʼ��L��ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
		ListInsert(&L,1,j);			/* ͷ�巨 */
    printf("  ��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L); 

    printf("  ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("  L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

	printf("*******************************************************************************\n");

    i=ClearList(&L);
    printf("\n#2:���L��ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("  L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);

    for(j=1;j<=10;j++)
		ListInsert(&L,j,j);		/* β�巨 */
    printf("  ��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 

    printf("  ListLength(L)=%d \n",ListLength(L));

	printf("*******************************************************************************\n");

    ListInsert(&L,1,0);
    printf("\n#3:��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    printf("  ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("  ��5��Ԫ�ص�ֵΪ��%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("  ��%d��Ԫ�ص�ֵΪ%d\n",k,j);
            else
                    printf("  û��ֵΪ%d��Ԫ��\n",j);
    }
    

    k=ListLength(L); /* kΪ�� */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(&L,j,&e); /* ɾ����j������ */
            if(i==ERROR)
                    printf("  ɾ����%d������ʧ��\n",j);
            else
                    printf("  ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    }
    printf("  �������L��Ԫ�أ�");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("  ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);

    printf("  �������L��Ԫ�أ�");
    ListTraverse(L); 

	printf("*******************************************************************************\n");

    i=ClearList(&L);
    printf("\n#4:���L��ListLength(L)=%d\n",ListLength(L));
	int n;
	printf("  ����L�е����ݸ���n��");
	scanf("%d",&n);
	printf("  ����L�е�Ԫ��:");
	for(j=1;j<=n;j++)
	{
		scanf("%d",&e);
		ListInsert(&L,j,e);
	}
	printf("  �������L�е�Ԫ�أ�");
	ListTraverse(L);

	InitList(&La);
	for(j=1;j<=5;j++)
		ListInsert(&La,j,j);
	printf("  �������La�е�Ԫ�أ�");
	ListTraverse(La);
	unionL(&L,La);
	printf("  ��������ϲ���La֮���L�е�Ԫ�أ�");
	ListTraverse(L);

	Bubble_Sort(&L);
	printf("  �����������֮���L��Ԫ�أ�");
	ListTraverse(L);

	printf("*******************************************************************************\n");

	int m;
	InitList(&Lb);
	printf("\n#5:����Lb�е����ݸ���m��");
	scanf("%d",&m);
	printf("  ����Lb�е�Ԫ��:");
	for(j=1;j<=m;j++)
	{
		scanf("%d",&e);
		ListInsert(&Lb,j,e);
	}
	printf("  �������Lb�е�Ԫ�أ�");
	ListTraverse(Lb);
	Bubble_Sort(&Lb);
	printf("  �����������֮���Lb��Ԫ�أ�");
	ListTraverse(Lb);

	InitList(&Lc);
	MergeList(&L,&Lb,&Lc);
	printf("  ���������L��Lb�鲢�õ���Lc��Ԫ�أ�");
	ListTraverse(Lc);

    return 0;
}


/* ����������ʽ���Ա�Lb�е�����La�е�����Ԫ�ز��뵽La�� */
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

/* ����ʽ���Ա�L�е�����Ԫ�ؽ������� */
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

/* ����ָ��px��py��ָ������� */
void Swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}

/* ��֪��ʽ���Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
   �鲢La��Lb�õ��µ���ʽ���Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
void MergeList(LinkList *La,LinkList *Lb,LinkList *Lc)
{
	LinkList pa,pb,pc;

	pa = (*La)->next;
	pb = (*Lb)->next;
	*Lc = *La;		/* ��La��ͷ�����ΪLc��ͷ��� */
	pc = *Lc;

	while(pa && pb)	/* La��Lb���ǿ� */
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
	pc->next = pa ? pa : pb;	/* ����ʣ��� */
}
