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
	3. ����������ѡ��ʵ�ַ�����
	4. ���������н���˳��������LA_Sq��LA_Lk����LB_Sq��LB_Lk����
	5. ���������зֱ�����˳��������LA_Sq��LA_Lk����LB_Sq��LB_Lk�������ݸ��������ݡ�
	6. ���������е��ú���Bubble_Sort_Sq(Bubble_Sort_Lk)�ֱ��LA_Sq��LA_Lk����LB_Sq��LB_Lk����������
	7. ���������кϲ�LA_Sq��LA_Lk����LB_Sq��LB_Lk��Ϊ�µ����Ա�LC��
*/

#include "SQLIST.H"			/* ����˳���Ķ��弰�������� */
#include "LKLIST.H"			/* ��������Ķ��弰�������� */

#define N 20

int main(void)
{
	int i , j , n_LA , n_LB , choice;
	ElemType e;

	/* ѡ�����ʵ�ַ��� */
	for(j=1 ; j<=3 ; j++)
	{
		/* ������ʾ�˵� */
		printf("[1]: ˳���ʵ�ַ��� \n");
		printf("[2]: ����ʵ�ַ��� \n");
		printf("[0]: �˳� \n");

		/* ѡ�����ʵ�ַ��� */
		do
		{
			printf("Enter choice:\n");
			scanf("%d",&choice);
		}while((choice!=0) && (choice!=1) && (choice!=2));
		
		/* ���������ѡ��ѡ��ͬ��ʵ�ַ��� */
		switch(choice)
		{
		case 1:
			SqList LA_Sq , LB_Sq , LC_Sq;

			InitList_Sq(&LA_Sq);
			InitList_Sq(&LB_Sq);
			InitList_Sq(&LC_Sq);

			/* ����LA�������ݵĸ��� */
			do
			{
				printf("������LA��Ԫ�صĸ���n_LA(0<=n_LA<=%d):\n",N);
				scanf("%d",&n_LA);
			}while((n_LA<0) || (n_LA>N));

			/* ����LA������ */
			printf("������LA�е�Ԫ�أ�");
			for(i=0 ; i<n_LA ; i++)
			{
				scanf("%d",&e);
				ListInsert_Sq(&LA_Sq,1,e);	/* ����ͷ�巨 */
			}
			printf("�����������֮ǰ��LA��Ԫ�أ�");
			ListTraverse_Sq(LA_Sq);

			/* ����LB�������ݵĸ��� */
			do
			{
				printf("������LB��Ԫ�صĸ���n_LB(0<=n_LB<=%d):\n",N);
				scanf("%d",&n_LB);
			}while((n_LB<0) || (n_LB>N));

			/* ����LB������ */
			printf("������LB�е�Ԫ�أ�");
			for(i=0 ; i < n_LB ; i++)
			{
				scanf("%d",&e);
				ListInsert_Sq(&LB_Sq,1,e);	/* ����ͷ�巨 */
			}
			printf("�����������֮ǰ��LB��Ԫ�أ�");
			ListTraverse_Sq(LB_Sq);

			Bubble_Sort_Sq(&LA_Sq);
			printf("�����������֮���LA��Ԫ�أ�");
			ListTraverse_Sq(LA_Sq);
			Bubble_Sort_Sq(&LB_Sq);
			printf("�����������֮���LB��Ԫ�أ�");
			ListTraverse_Sq(LB_Sq);
			
			MergeList_Sq(LA_Sq,LB_Sq,&LC_Sq);
			printf("��������ɺϲ�LA��LB�õ���LC�е�Ԫ�أ�");
			ListTraverse_Sq(LC_Sq);
			break;
		case 2:
			LinkList LA_Lk , LB_Lk , LC_Lk;

			InitList_Lk(&LA_Lk);
			InitList_Lk(&LB_Lk);
			InitList_Lk(&LC_Lk);

			/* ����LA�������ݵĸ��� */
			do
			{
				printf("������LA��Ԫ�صĸ���n_LA(0<=n_LA<=%d):\n",N);
				scanf("%d",&n_LA);
			}while((n_LA<0) || (n_LA>N));

			/* ����LA������ */
			printf("������LA�е�Ԫ�أ�");
			for(i=0 ; i < n_LA ; i++)
			{
				scanf("%d",&e);
				ListInsert_Lk(&LA_Lk,1,e);	/* ����ͷ�巨 */
			}
			printf("�����������֮ǰ��LA��Ԫ�أ�");
			ListTraverse_Lk(LA_Lk);

			/* ����LB�������ݵĸ��� */
			do
			{
				printf("������LB��Ԫ�صĸ���n_LB(0<=n_LB<=%d):\n",N);
				scanf("%d",&n_LB);
			}while((n_LB<0) || (n_LB>N));

			/* ����LB������ */
			printf("������LB�е�Ԫ�أ�");
			for(i=0 ; i < n_LB ; i++)
			{
				scanf("%d",&e);
				ListInsert_Lk(&LB_Lk,1,e);	/* ����ͷ�巨 */
			}
			printf("�����������֮ǰ��LB��Ԫ�أ�");
			ListTraverse_Lk(LB_Lk);

			Bubble_Sort_Lk(&LA_Lk);
			printf("�����������֮���LA��Ԫ�أ�");
			ListTraverse_Lk(LA_Lk);
			Bubble_Sort_Lk(&LB_Lk);
			printf("�����������֮���LB��Ԫ�أ�");
			ListTraverse_Lk(LB_Lk);
			
			MergeList_Lk(&LA_Lk , &LB_Lk , &LC_Lk);
			printf("��������ɺϲ�LA��LB�õ���LC�е�Ԫ�أ�");
			ListTraverse_Lk(LC_Lk);
			break;
		default:
			break;
		}
	
		printf("***************************************************\n");
	}
	
	return 0;
}



