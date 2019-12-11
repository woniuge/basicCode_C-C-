//��ͷ���ľ�̬������

#include <stdio.h>


#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef char ElemType;	/* ElemType���͸���ʵ������������������Ϊchar */



/* ���Ա�ľ�̬������洢�ṹ */
typedef struct {
    ElemType data;
    int cur;  /* �α�(Cursor) ��Ϊ0ʱ��ʾָ��ͷ��� */
}component,SLinkList[MAXSIZE];


Status visit(ElemType e) {
	//������Ԫ��e���
	printf("%c ",e);
	return  OK;
}// visit

Status InitSpace_SL(SLinkList &space) {
	// ��һά����space�и���������һ����������space[0].curΪͷָ�룬
	// "0"��ʾ��ָ��
	for (int i = 0; i < MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; /* ���һ��Ԫ�ص�curΪ0 */
	return OK;
}// InitSpace_SL

int Malloc_SL(SLinkList &space) {
	// �����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
	int i = space[0].cur;	// ��ǰ�����һ��Ԫ�ص�cur���ֵ
	                        // ����Ҫ���صĵ�һ�����ÿռ���±�
	if (space[0]. cur)         
	    space[0]. cur = space[i].cur;  // ����Ҫ�ó�һ��������ʹ����,
                           	           // �������Ǿ͵ð�������һ��
									   // ��������������
	return i;
}// Malloc_SL

void Free_SL(SLinkList &space, int k) {
	// ���±�Ϊk�Ŀ��н����յ���������
    space[k].cur = space[0].cur;  // �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ�����cur
    space[0].cur = k;             // ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur
}// Free_SL

int Length_SL(SLinkList S) {
	// ��ʼ��������̬����L�Ѵ��ڡ�
	// �������������L������Ԫ�ظ���
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
	// ��S�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e
    int j, k, l;   
    k = 0;   // ע��k�����ǵ�һ��Ԫ�ص��±�
    if (i < 1 || i > Length_SL(S) + 1)   // ����Ϸ��Լ��
        return ERROR;   
    j = Malloc_SL(space);   // ��ÿ��з������±�
    if (j)   
    {   
		S[j].data = e;   // �����ݸ�ֵ���˷�����data
		for(l = 1; l <= i - 1; l++)   // �ҵ���i-1��Ԫ�ص�λ��
		   k = S[k].cur;           
		S[j].cur = S[k].cur;    // �ѵ�i-1��Ԫ�ص�cur��ֵ����Ԫ�ص�cur
		S[k].cur = j;    // ����Ԫ�ص��±긳ֵ����i-1��Ԫ�ص�cur
		return OK;   
    }   
    return ERROR;   
}// Insert_SL

Status Delete_SL(SLinkList &S,int i, SLinkList &space) {
	// ɾ����L�е�i������Ԫ�� 
	int j,k;
    if (i < 1 || i > Length_SL(S))  // ����Ϸ��Լ��
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
	// ������̬�����Ԫ��
    int i=S[0].cur;
    while(i)
    {
		visit(S[i].data);
        i=S[i].cur;
    }
    printf("\n");
    return OK;
}// Traverse_SL
