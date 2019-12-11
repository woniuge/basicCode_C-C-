/* 布袋中的彩色球（用指向指针的指针实现） */
#include <stdio.h>

int main(void)
{
	char * color[5]={"red","blue","yellow","green","purple"};
	char **pc=color;
	int count=0,i,j;

	for(i=0;i<=4;i++)
		for(j=0;j<=4;j++)
		{
			if(i==j)
				continue;
			count++;
			printf("%6d",count);
			printf("%10s %10s\n",*(pc+i),*(pc+j));
		}

		printf("1 %x\n",pc);
		printf("2 %x\n",color);
		printf("3 %x\n",&color[0]);
		printf("4 %x\n",color[0]);
		printf("5 %-10s\n",*color);
		printf("6 %-10s\n",color[0]);
		printf("7 %-10s\n",*pc);
		printf("8 %x\n",*pc);
		printf("9 %x\n",&"red");
		printf("10 %c\n",**pc);
		printf("11 %c\n",**(pc+1));
		printf("12 %c\n",*(*pc+1));
		printf("10 %c\n",*(color[0]+2));
		printf("13 %c\n",*color[0]);
	
		return 0;
}