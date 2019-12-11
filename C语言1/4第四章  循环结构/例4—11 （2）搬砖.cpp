/* 45人正好搬45块砖，程序版本2 */
#include <stdio.h>

int main(void)
{
	int men,women,child;

	for(men=0;men<=15;men++)
		for(women=0;women<=22;women++)
		{
			child=45-men-women;
			if(men*3+women*2+child*0.5==45)
				printf("men=%d,women=%d,child=%d\n",men,women,child);
		}

	return 0;
}