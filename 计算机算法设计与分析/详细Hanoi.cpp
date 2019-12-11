/*	��ϸģ�⺺ŵ���İ��ƹ��̣�
	��a[]��b[]��c[]�ֱ��ʾa��b��c���������ϵĵ��Ӽ��ϣ�
	������С�����˳��ֱ�����ӱ��1,2,3����������Ӧ�����±�һһ��Ӧ��
	��a1��b1��c1�ֱ��ʾ�������ӵı��
*/


#include <stdio.h>
#define M 101

int m;

void hanoi(int n, int a[], int b[], int c[], char a1, char b1, char c1);
void move(int n, int a[], int b[], char a1, char b1);
void state(int n, int a[], int b[], int c[]);		/* ������������еĴ洢���� */

int main(void)
{
	int i;
	int n;
	int al[M] = {0},bl[M] = {0},cl[M] = {0};

	char a1 = 'a';	/* a1��ʾ����a�ϵ�Ԫ�� */
	char b1 = 'b';	/* b1��ʾ����b�ϵ�Ԫ�� */
	char c1 = 'c';	/* c1��ʾ����c�ϵ�Ԫ�� */

	do{
		printf("�����뺺ŵ����������");
		scanf("%d",&n);
	}while(n <= 0);

	for(i = 1 ; i <= n ; i++)
		al[i] = i;

	printf("\n��ʼ״̬��\n");	/* �����������ĳ�ʼ���� */
	state(n, al, bl, cl);

	printf("\n���ƹ��̣�\n");

	hanoi(n, al, bl, cl, a1, b1, c1);

	printf("\n����֮��\n");	/* �������֮��������������� */
	state(n, al, bl, cl);

	return 0;
}
void hanoi(int n, int a[], int b[], int c[], char a1, char b1, char c1)
{
	if(n>0)
	{
		hanoi(n-1, a, c, b, a1, c1, b1);
		move(n, a, b, a1, b1);
		hanoi(n-1, c, b, a, c1, b1, a1);
	}
}

void move(int n, int a[], int b[], char a1, char b1)
{
	printf("��%d�����ѵ� %d �����Ӵ� %c �Ƶ� %c \n",++m,n,a1,b1);
	a[n] = 0;
	b[n] = n;
}

void state(int n, int a[], int b[], int c[])
{
	int i;

	printf("a[%d]:",n);
	for(i = 1 ; i <= n ; i++)
		printf("%d ",a[i]);
	printf("\n");

	printf("b[%d]:",n);
	for(i = 1 ; i <= n ; i++)
		printf("%d ",b[i]);
	printf("\n");

	printf("c[%d]:",n);
	for(i = 1 ; i <= n ; i++)
		printf("%d ",c[i]);
	printf("\n");
}