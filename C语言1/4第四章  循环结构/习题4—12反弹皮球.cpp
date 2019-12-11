/* 皮球从height米的高度自由落下，触地后反弹到原高度的一半，
再落下，再反弹，如此反复。皮球在第n次反弹落地时，在空中经
过的路程是多少米？第n次反弹的高度是多少？（输出保留一位小
数） */
#include <stdio.h>

int main(void)
{
	int i,n;
	double distance,height;

	printf("input height:");
	scanf("%lf",&height);
	printf("input n:");
	scanf("%d",&n);

	distance=height;
	for(i=1;i<=n;i++)
	{
		height=height/2;
		distance=distance+height*2;
	}

	printf("distance=%.1lf\nheight=%.1lf\n",distance,height);

	return 0;
}
