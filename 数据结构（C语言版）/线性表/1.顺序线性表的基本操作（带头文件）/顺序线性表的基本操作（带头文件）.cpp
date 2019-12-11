
#include "SQLIST.H"	/* ˳���Ļ������������� */

void unionL(SqList *La,SqList Lb);	/* ��������˳���Lb�е�����La�е�����Ԫ�ز��뵽La�� */
void Bubble_Sort(SqList *L);	/* ��˳���L�е�����Ԫ�ؽ������� */
void Swap(int *px,int *py);	/* ����ָ��px��py��ָ������� */

/* ��֪˳���La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
   �鲢La��Lb�õ��µ�˳���Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
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
    printf("1#:��ʼ��L��L.length=%d,i=%d\n",L.length,i);
	printf("*******************************************************************************\n");

    for(j=1;j<=5;j++)
		ListInsert(&L,1,j);		/* ����β�巨 */
    printf("\n2#:��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L);
	printf("*******************************************************************************\n");

    printf("\n3#:L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("  L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
	printf("*******************************************************************************\n");

    i=ClearList(&L);
    printf("\n4#:���L��L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("  L�Ƿ�գ�i=%d(1:�� 0:��)\n",i);
	printf("*******************************************************************************\n");

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);		/* ����ͷ�巨 */
    printf("\n5#:��L�ı�β���β���1��10��L.data=");
    ListTraverse(L); 
	printf("  L.length=%d \n",L.length);
	printf("*******************************************************************************\n");

    ListInsert(&L,1,0);
    printf("\n6#:��L�ı�ͷ����0��L.data=");
    ListTraverse(L); 
    printf("  L.length=%d \n",L.length);
	printf("*******************************************************************************\n");

    GetElem(L,5,&e);
    printf("\n7#:��5��Ԫ�ص�ֵΪ��%d\n",e);

    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("  ��%d��Ԫ�ص�ֵΪ��%d\n",k,j);
            else
                    printf("  û��ֵΪ%d��Ԫ��\n",j);
    }
	printf("*******************************************************************************\n");

    k=ListLength(L); /* kΪ�� */
	printf("\n8#:L�ı�Ϊ��%d\n",k);
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
	printf("*******************************************************************************\n");

    j=5;
    ListDelete(&L,j,&e); /* ɾ����5������ */
    printf("\n9#:ɾ����%d����Ԫ��ֵΪ��%d\n",j,e);
    printf("  �������L��Ԫ�أ�");
    ListTraverse(L); 
	printf("*******************************************************************************\n");

	/* ����һ����10������Lb */
	InitList(&Lb);
    for(j=6;j<=15;j++)
		ListInsert(&Lb,1,j);
	printf("\n10#:�������Lb��Ԫ�أ�");
	ListTraverse(Lb);
	unionL(&L,Lb);
	printf("  ��������ϲ���Lb��L��Ԫ�أ�");
    ListTraverse(L); 
	printf("*******************************************************************************\n");

	int n;
	InitList(&Lc);
	printf("\n11#:������Lc��Ԫ�صĸ���n��");
	scanf("%d",&n);
	printf("  ������Lc�е�Ԫ�أ�");
	for(i=0;i<n;i++)
	{
		scanf("%d",&e);
		ListInsert(&Lc,1,e);	/* ����ͷ�巨 */
	}
	printf("  �����������֮ǰ��Lc��Ԫ�أ�");
	ListTraverse(Lc);
	Bubble_Sort(&Lc);
	printf("  �����������֮���Lc��Ԫ�أ�");
	ListTraverse(Lc);
	printf("*******************************************************************************\n");

	printf("\n12#�������������֮ǰ��Lb�е�Ԫ�أ�");
	ListTraverse(Lb);
	Bubble_Sort(&Lb);
	printf("  �����������֮���Lb�е�Ԫ�أ�");
	ListTraverse(Lb);
	printf("  �����������֮���Lc��Ԫ�أ�");
	ListTraverse(Lc);
	MergeList(Lb,Lc,&Ld);
	printf("  ��������ɹ鲢Lb��Lc�õ���Ld�е�Ԫ�أ�");
	ListTraverse(Ld);
	printf("*******************************************************************************\n");

    return 0;
}

/* ��������˳���Lb�е�����La�е�����Ԫ�ز��뵽La�� */
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

/* ��˳���L�е�����Ԫ�ؽ������� */
void Bubble_Sort(SqList *L)
{
	int i,j;

	for(i=1;i<L->length;i++)
		for(j=0;j< L->length-i;j++)
			if(L->data[j] > L->data[j+1])
				Swap(&L->data[j],&L->data[j+1]);
}

/* ����ָ��px��py��ָ������� */
void Swap(int *px,int *py)
{
	int t;

	t=*px;
	*px=*py;
	*py=t;
}

/* ��֪˳���La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
   �鲢La��Lb�õ��µ�˳���Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����� */
void MergeList(SqList La,SqList Lb,SqList *Lc)
{
	int i,j,k=0;      

	InitList(Lc);
	i=j=1;
	La.length = ListLength(La);
	Lb.length = ListLength(Lb);
	while((i<=La.length) && (j<=Lb.length))	/* La��Lb���ǿ� */
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