/* ����һ��������ͳ�Ʋ���������������֡�2���ĸ�����Ҫ����͵��ú���
countdigit��number��digit�������Ĺ�����ͳ������number������digit�ĸ�����
���磬countdigit��10090,0���ķ���ֵ��3�� */
#include <stdio.h>
int countdigit(int number,int digit);

int main(void)
{
	int digit,count,number;

	printf("enter number and digit:");
	scanf("%d%d",&number,&digit);

	count=countdigit(number,digit);
	
	printf("countdigit(%d,%d)=%d\n",number,digit,count);

	return 0;
}

int countdigit(int number,int digit)
{
	int result,item;

	result=0;
	do{
		item=number%10;
		if(item==digit)
			result++;
		number=number/10;
	  }while(number!=0);

	return result;
}

