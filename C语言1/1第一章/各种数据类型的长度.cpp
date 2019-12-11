/* 各种数据类型所占的字节数 */
#include <stdio.h>

int main(void)
{
	struct
	{
		int num;
		char name[12];
		union
		{
			double class1;
			char position[12];
		};
	}a;
	printf("1#	%d\n",sizeof(a));
	printf("2#	%d\n",sizeof(char));
	printf("3#	%d\n",sizeof(short));
	printf("4#	%d\n",sizeof(int));
	printf("5#	%d\n",sizeof(unsigned short));
	printf("6#	%d\n",sizeof(unsigned));
	printf("7#	%d\n",sizeof(long));
	printf("8#	%d\n",sizeof(unsigned long));
	printf("9#	%d\n",sizeof(float));
	printf("10#	%d\n",sizeof(double))

	return 0;
}