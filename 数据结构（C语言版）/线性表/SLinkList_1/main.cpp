

#include "SLinkList.h"

void difference(SLinkList &space , int &S);

int main(void)
{
	SLinkList space;
	Status i;
	i = InitSpace_SL(space);
	printf("��ʼ��space��:space.length = %d\n",Length_SL(space));

	int S;
	S = Malloc_SL(space);
	difference(space,S);

	return 0;
}

void difference(SLinkList &space , int &S) {
	// �������뼯��A��B��Ԫ�أ���һά����space�н�����ʾ����(A - B)U(B - A)
	// �ľ�̬����SΪ��ͷָ�롣���豸�ÿռ��㹻��space[0].curΪ��ͷָ�롣
	int r = S;	// rָ��S�ĵ�ǰ�����
	int i, j;
	int m, n;
	scanf("%d %d",&m, &n);	// ����A��B��Ԫ�ظ���
	getchar();
	for(j = 1;j <= m; j++){	// ��������A������
		i = Malloc_SL(space);	// ������
		scanf("%c",&space[i].data);	//����A��Ԫ��ֵ
		space[r].cur = i;	// ���뵽��β
		r = i ;
	}// for
	space[r].cur = 0;		// β����ָ��Ϊ��
	char b;
	int p,k;

	getchar();
	for(j = 1; j <= n; j++){	// ��������B��Ԫ�أ������ڵ�ǰ���У�����룬����ɾ��
		scanf("%c",b);
		p = S;
		k = space[S].cur;	// kָ�򼯺�A�е�һ�����
		while(k != space[r].cur && space[k].data != b){	// �ڵ�ǰ���в���
			p = k;
			k = space[k].cur;
		}// while
		if(k == space[r].cur){	// ��ǰ���в����ڸ�Ԫ�أ�������r��ָ���֮����r��λ�ò���
			i = Malloc_SL(space);
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
		}//if
		else {			//��Ԫ�����ڱ��У�ɾ��֮
			space[p].cur = space[k].cur;
			Free_SL(space, k);
			if(r == k)		// ��ɾ������r��ָ��㣬�����޸�βָ��
				r == p;
		}// else
	}//for	
}//difference
