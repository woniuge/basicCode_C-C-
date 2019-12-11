//带头结点的静态单链表

#include <stdio.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef char ElemType;	/* ElemType类型根据实际情况而定，这里假设为char */



/* 线性表的静态单链表存储结构 */
typedef struct {
    ElemType data;
    int cur;  /* 游标(Cursor) ，为0时表示指向头结点 */
}component,SLinkList[MAXSIZE];


Status visit(ElemType e) {
	//将数据元素e输出
	printf("%c ",e);
	return  OK;
}// visit

Status InitSpace_SL(SLinkList &space) {
	// 将一维数组space中各分量链成一个备用链表，space[0].cur为头指针，
	// "0"表示空指针
	for (int i = 0; i < MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* 最后一个元素的cur为0 */
	return OK;
}// InitSpace_SL

int Malloc_SL(SLinkList &space) {
	// 若备用空间链表非空，则返回分配的结点下标，否则返回0
	int i = space[0].cur;	// 当前数组第一个元素的cur存的值
	                        // 就是要返回的第一个备用空间的下标
	if (space[0]. cur)         
	    space[0]. cur = space[i].cur;  // 由于要拿出一个分量来使用了,
                           	           // 所以我们就得把它的下一个
									   // 分量用来做备用
	return i;
}// Malloc_SL

void Free_SL(SLinkList &space, int k) {
	// 将下标为k的空闲结点回收到备用链表
    space[k].cur = space[0].cur;  // 把第一个元素的cur值赋给要删除的分量的cur
    space[0].cur = k;             // 把要删除的分量下标赋值给第一个元素的cur
}// Free_SL

int Length_SL(SLinkList S) {
	// 初始条件：静态链表L已存在。
	// 操作结果：返回L中数据元素个数
    int j = 0;
    int i = S[0].cur;
    while(i)
    {
        i=S[i].cur;
        j++;
    }
    return j;
}// Length_SL

Status Insert_SL(SLinkList S, int i, ElemType e, SLinkList &space) {
	// 在S中第i个元素之前插入新的数据元素e
    int j, k, l;   
    k = 0;   // 注意k首先是第一个元素的下标
    if (i < 1 || i > Length_SL(S) + 1)   // 输入合法性检查
        return ERROR;   
    j = Malloc_SL(space);   // 获得空闲分量的下标
    if (j)   
    {   
		S[j].data = e;   // 将数据赋值给此分量的data
		for(l = 1; l <= i - 1; l++)   // 找到第i-1个元素的位置
		   k = S[k].cur;           
		S[j].cur = S[k].cur;    // 把第i-1个元素的cur赋值给新元素的cur
		S[k].cur = j;    // 把新元素的下标赋值给第i-1个元素的cur
		return OK;   
    }   
    return ERROR;   
}// Insert_SL

Status Delete_SL(SLinkList &S,int i, SLinkList &space) {
	// 删除在L中第i个数据元素 
	int j,k;
    if (i < 1 || i > Length_SL(S))  // 输入合法性检查
        return ERROR;   
    k = 0;
    for (j = 1; j <= i - 1; j++)   
        k = S[k].cur;   
    j = S[k].cur;   
    S[k].cur = S[j].cur;   
    Free_SL(space, j);   
    return OK;   
} // Delete_SL

Status Traverse_SL(SLinkList S) {
	// 遍历静态链表的元素
    int i=S[0].cur;
    while(i)
    {
		visit(S[i].data);
        i=S[i].cur;
    }
    printf("\n");
    return OK;
}// Traverse_SL
