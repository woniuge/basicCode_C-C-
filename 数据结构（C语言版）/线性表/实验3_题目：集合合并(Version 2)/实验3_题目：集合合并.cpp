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
	3. 在主函数中选择实现方法。
	4. 在主函数中建立顺序（链）表LA_Sq（LA_Lk）和LB_Sq（LB_Lk）。
	5. 在主函数中分别输入顺序（链）表LA_Sq（LA_Lk）和LB_Sq（LB_Lk）的数据个数及数据。
	6. 在主函数中调用函数Bubble_Sort_Sq(Bubble_Sort_Lk)分别对LA_Sq（LA_Lk）和LB_Sq（LB_Lk）进行排序。
	7. 在主函数中合并LA_Sq（LA_Lk）与LB_Sq（LB_Lk）为新的线性表LC。
*/

#include "SQLIST.H"			/* 包含顺序表的定义及基本操作 */
#include "LKLIST.H"			/* 包含链表的定义及基本操作 */

#define N 20

int main(void)
{
	int i , j , n_LA , n_LB , choice;
	ElemType e;

	/* 选择操作实现方法 */
	for(j=1 ; j<=3 ; j++)
	{
		/* 三行显示菜单 */
		printf("[1]: 顺序表实现方法 \n");
		printf("[2]: 链表实现方法 \n");
		printf("[0]: 退出 \n");

		/* 选择操作实现方法 */
		do
		{
			printf("Enter choice:\n");
			scanf("%d",&choice);
		}while((choice!=0) && (choice!=1) && (choice!=2));
		
		/* 根据输入的选项选择不同的实现方法 */
		switch(choice)
		{
		case 1:
			SqList LA_Sq , LB_Sq , LC_Sq;

			InitList_Sq(&LA_Sq);
			InitList_Sq(&LB_Sq);
			InitList_Sq(&LC_Sq);

			/* 控制LA输入数据的个数 */
			do
			{
				printf("请输入LA中元素的个数n_LA(0<=n_LA<=%d):\n",N);
				scanf("%d",&n_LA);
			}while((n_LA<0) || (n_LA>N));

			/* 输入LA的数据 */
			printf("请输入LA中的元素：");
			for(i=0 ; i<n_LA ; i++)
			{
				scanf("%d",&e);
				ListInsert_Sq(&LA_Sq,1,e);	/* 采用头插法 */
			}
			printf("依次输出排序之前的LA的元素：");
			ListTraverse_Sq(LA_Sq);

			/* 控制LB输入数据的个数 */
			do
			{
				printf("请输入LB中元素的个数n_LB(0<=n_LB<=%d):\n",N);
				scanf("%d",&n_LB);
			}while((n_LB<0) || (n_LB>N));

			/* 输入LB的数据 */
			printf("请输入LB中的元素：");
			for(i=0 ; i < n_LB ; i++)
			{
				scanf("%d",&e);
				ListInsert_Sq(&LB_Sq,1,e);	/* 采用头插法 */
			}
			printf("依次输出排序之前的LB的元素：");
			ListTraverse_Sq(LB_Sq);

			Bubble_Sort_Sq(&LA_Sq);
			printf("依次输出排序之后的LA的元素：");
			ListTraverse_Sq(LA_Sq);
			Bubble_Sort_Sq(&LB_Sq);
			printf("依次输出排序之后的LB的元素：");
			ListTraverse_Sq(LB_Sq);
			
			MergeList_Sq(LA_Sq,LB_Sq,&LC_Sq);
			printf("依次输出由合并LA和LB得到的LC中的元素：");
			ListTraverse_Sq(LC_Sq);
			break;
		case 2:
			LinkList LA_Lk , LB_Lk , LC_Lk;

			InitList_Lk(&LA_Lk);
			InitList_Lk(&LB_Lk);
			InitList_Lk(&LC_Lk);

			/* 控制LA输入数据的个数 */
			do
			{
				printf("请输入LA中元素的个数n_LA(0<=n_LA<=%d):\n",N);
				scanf("%d",&n_LA);
			}while((n_LA<0) || (n_LA>N));

			/* 输入LA的数据 */
			printf("请输入LA中的元素：");
			for(i=0 ; i < n_LA ; i++)
			{
				scanf("%d",&e);
				ListInsert_Lk(&LA_Lk,1,e);	/* 采用头插法 */
			}
			printf("依次输出排序之前的LA的元素：");
			ListTraverse_Lk(LA_Lk);

			/* 控制LB输入数据的个数 */
			do
			{
				printf("请输入LB中元素的个数n_LB(0<=n_LB<=%d):\n",N);
				scanf("%d",&n_LB);
			}while((n_LB<0) || (n_LB>N));

			/* 输入LB的数据 */
			printf("请输入LB中的元素：");
			for(i=0 ; i < n_LB ; i++)
			{
				scanf("%d",&e);
				ListInsert_Lk(&LB_Lk,1,e);	/* 采用头插法 */
			}
			printf("依次输出排序之前的LB的元素：");
			ListTraverse_Lk(LB_Lk);

			Bubble_Sort_Lk(&LA_Lk);
			printf("依次输出排序之后的LA的元素：");
			ListTraverse_Lk(LA_Lk);
			Bubble_Sort_Lk(&LB_Lk);
			printf("依次输出排序之后的LB的元素：");
			ListTraverse_Lk(LB_Lk);
			
			MergeList_Lk(&LA_Lk , &LB_Lk , &LC_Lk);
			printf("依次输出由合并LA和LB得到的LC中的元素：");
			ListTraverse_Lk(LC_Lk);
			break;
		default:
			break;
		}
	
		printf("***************************************************\n");
	}
	
	return 0;
}



