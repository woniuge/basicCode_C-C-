/* 模拟简单运算器,运算repeat次,操作数operand */
#include <stdio.h>

int main(void)
{
	int repeat,ri;
	int operand1,operand2,result;
	char ch;

	printf("enter repeat:");
	scanf("%d",&repeat);
	for(ri=1;ri<=repeat;ri++)
	{
		printf("Type in an expression:\n");
		scanf("%d",&operand1);
		ch=getchar();
		result=operand1;
		while(ch!='=')
		{
			scanf("%d",&operand2);
			switch(ch)
			{
			case'+':result+=operand2;break;
			case'-':result-=operand2;break;
			case'*':result*=operand2;break;
			case'/':result/=operand2;break;
			}

			ch=getchar();
		}
		printf("%d\n",result);
	}
	return 0;	
}	
