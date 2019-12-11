/* 求解简单的四则运算表达式（改良版） */
#include <stdio.h>

int main(void)
{
	double value1,value2;
	char ch;

	printf("type in a expression:");
	scanf("%lf%c%lf",&value1,&ch,&value2);

	switch(ch)
	{
		case'+':
			printf("=%.2f\n",value1+value2);
			break;
		case'-':
			printf("=%.2f\n",value1-value2);
			break;
		case'*':
			printf("=%.2f\n",value1*value2);
			break;
		case'/':
			if(value2==0)
			{
				printf("=error\n",value1/value2);
			}
			else
			{
				printf("=%.2f\n",value1/value2);
			}
			break;
		default:
			printf("unknown operator\n");
			break;			
	}

	return 0;
}