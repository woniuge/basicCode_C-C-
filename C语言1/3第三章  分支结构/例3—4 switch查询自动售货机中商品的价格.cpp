/* switch 查询自动售货机中商品的价格 */
#include <stdio.h>

int main(void)
{
	int i,choice;
	double price;

	for(i=1;i<=5;i++)							/* for的循环体语句开始 */
	{	
		/* 以下5行显示菜单 */
		printf("[1] select crisps \n");			/* 查询薯片价格 */
		printf("[2] select popcorn \n");		/* 查询爆米花价格 */
		printf("[3] select chocolate \n");		/* 查询巧克力价格 */
		printf("[4] select cola \n");			/* 查询可乐价格 */
		printf("[0] exit \n");					/* 退出查询 */

		printf("enter choice:");				/* 输入提示 */
		scanf("%d",&choice);					/* 接受用户输入的编号 */

		/* 如果输入0，提前结束for循环 */
		if(choice==0)
			break;								/* 此处用break跳出for循环 */
		/* 根据输入的编号，将相应的价格赋给price */
		switch(choice)
		{
			case 1:price=3.0;break;				/* 用break跳出switch语句，下同 */
			case 2:price=2.5;break;
			case 3:price=4.0;break;
			case 4:price=3.5;break;
			default:price=0.0;break;
		}
		
		/* 输出商品的价格 */
		printf("price=%0.1f\n",price);
	}											/* for的循环体语句结束 */

	printf("thanks! \n");						/* 结束查询，谢谢用户使用 */

	return 0;
}