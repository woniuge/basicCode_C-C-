/*  有n盏灯，编号为1~n。第一个人把所有灯打开，第二个人按下所有
编号为2的倍数的开关（这些灯将被关掉），第三个人按下所有编号为3
的倍数的开关（其中关掉的灯将被打开，开着的灯将被关闭），依次类
推，一共有k个人，问最后有哪些灯开着？输入：n和k，输出开着的灯
编号。k<=n<=1000	样例输入：7 3 样例输出：1 5 6 7  */
#include <stdio.h>

int main(void)
{
	int i,j,n,k,first;
	int a[1010];

	printf("enter n and k:");
	scanf("%d%d",&n,&k);

	for(i=1;i<=n;i++)
		a[i]=1;

	for(j=2;j<=k;j++)
		for(i=1;i<=n;i++)
			if(i%j==0)
				a[i]=-a[i];

	first=1;
	for(i=1;i<=n;i++)
	{
		if(a[i]==1)
		{
			if(first)
				first=0;
			else
				printf(" ");

			printf("%d",i);
		}
	}

	printf("\n");

	return 0;
}