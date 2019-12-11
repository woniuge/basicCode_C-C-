/*	详细模拟汉诺塔的搬移过程：
	用a[]，b[]，c[]分别表示a，b，c三根柱子上的碟子集合，
	并按从小到大的顺序分别给盘子编号1,2,3。。。与相应数组下标一一对应，
	用a1，b1，c1分别表示三根柱子的编号
*/


#include <stdio.h>
#define M 101

int m;

void hanoi(int n, int a[], int b[], int c[], char a1, char b1, char c1);
void move(int n, int a[], int b[], char a1, char b1);
void state(int n, int a[], int b[], int c[]);		/* 输出三个数组中的存储内容 */

int main(void)
{
	int i;
	int n;
	int al[M] = {0},bl[M] = {0},cl[M] = {0};

	char a1 = 'a';	/* a1表示塔座a上的元素 */
	char b1 = 'b';	/* b1表示塔座b上的元素 */
	char c1 = 'c';	/* c1表示塔座c上的元素 */

	do{
		printf("请输入汉诺塔的盘数：");
		scanf("%d",&n);
	}while(n <= 0);

	for(i = 1 ; i <= n ; i++)
		al[i] = i;

	printf("\n初始状态：\n");	/* 输出三个数组的初始内容 */
	state(n, al, bl, cl);

	printf("\n搬移过程：\n");

	hanoi(n, al, bl, cl, a1, b1, c1);

	printf("\n搬移之后：\n");	/* 输出搬移之后三个数组的内容 */
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
	printf("第%d步：把第 %d 个盘子从 %c 移到 %c \n",++m,n,a1,b1);
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