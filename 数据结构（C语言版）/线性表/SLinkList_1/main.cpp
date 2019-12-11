

#include "SLinkList.h"

void difference(SLinkList &space , int &S);

int main(void)
{
	SLinkList space;
	Status i;
	i = InitSpace_SL(space);
	printf("初始化space后:space.length = %d\n",Length_SL(space));

	int S;
	S = Malloc_SL(space);
	difference(space,S);

	return 0;
}

void difference(SLinkList &space , int &S) {
	// 依次输入集合A和B的元素，在一维数组space中建立表示集合(A - B)U(B - A)
	// 的静态链表，S为其头指针。假设备用空间足够大，space[0].cur为其头指针。
	int r = S;	// r指向S的当前最后结点
	int i, j;
	int m, n;
	scanf("%d %d",&m, &n);	// 输入A和B的元素个数
	getchar();
	for(j = 1;j <= m; j++){	// 建立集合A的链表
		i = Malloc_SL(space);	// 分配结点
		scanf("%c",&space[i].data);	//输入A的元素值
		space[r].cur = i;	// 插入到表尾
		r = i ;
	}// for
	space[r].cur = 0;		// 尾结点的指针为空
	char b;
	int p,k;

	getchar();
	for(j = 1; j <= n; j++){	// 依次输入B的元素，若不在当前表中，则插入，否则删除
		scanf("%c",b);
		p = S;
		k = space[S].cur;	// k指向集合A中第一个结点
		while(k != space[r].cur && space[k].data != b){	// 在当前表中查找
			p = k;
			k = space[k].cur;
		}// while
		if(k == space[r].cur){	// 当前表中不存在该元素，插入在r所指结点之后，且r的位置不变
			i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}//if
		else {			//该元素已在表中，删除之
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if(r == k)		// 若删除的是r所指结点，则需修改尾指针
				r == p;
		}// else
	}//for	
}//difference
