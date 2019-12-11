/* 用指针数组输出5种颜色的英文名称 */
#include <stdio.h>

int main(void)
{
	int i;
	char * color[5]={"red","blue","yellow","green","purple"},*tmp;

	for(i=0;i<=4;i++)
		printf("%x,%s\n",color[i],color[i]);

	printf("1  %x\n",color);
	printf("2  %x\n",color[0]);
	printf("3  %x\n",* color[0]);
	printf("4  %x\n",* color);
	printf("5  %s\n",* color);
	printf("6  %c\n",* color[0]);
	printf("7  %x\n",&"red");

	tmp=color[0];
	color[0]=color[4];
	color[4]=tmp;
	printf("color[0]:%s,color[4]:%s\n",color[0],color[4]);

	printf("%x\n",* color);
	printf("%s\n",* color);
	printf("%c\n",* color[0]);
	printf("%x\n",&"red");


	return 0;
}