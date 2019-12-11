/* 45人正好搬45块砖，程序版本1 */
#include <stdio.h>

int main(void)
{
	int men,women,child;

	for(men=0;men<=45;men++)
		for(women=0;women<=45;women++)
			for(child=0;child<=45;child++)
				if(men+women+child==45&&men*3+women*2+child*0.5==45)
					printf("men=%d,women=%d,child=%d\n",men,women,child);

	return 0;
}