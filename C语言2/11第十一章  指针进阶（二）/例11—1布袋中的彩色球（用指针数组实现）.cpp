/* 布袋中的彩色球（用指针数组实现） */
#include <stdio.h>

int main(void)
{
	char * color[5]={"red","blue","yellow","green","purple"};
	int count=0,i,j;

	for(i=0;i<=4;i++)
		for(j=0;j<=4;j++)
		{
			if(i>=j)
				continue;
			count++;
			printf("%6d",count);
			printf("%10s %10s\n",color[i],color[j]);
		}

		return 0;
}