/* switch ��ѯ�Զ��ۻ�������Ʒ�ļ۸� */
#include <stdio.h>

int main(void)
{
	int i,choice;
	double price;

	for(i=1;i<=5;i++)							/* for��ѭ������俪ʼ */
	{	
		/* ����5����ʾ�˵� */
		printf("[1] select crisps \n");			/* ��ѯ��Ƭ�۸� */
		printf("[2] select popcorn \n");		/* ��ѯ���׻��۸� */
		printf("[3] select chocolate \n");		/* ��ѯ�ɿ����۸� */
		printf("[4] select cola \n");			/* ��ѯ���ּ۸� */
		printf("[0] exit \n");					/* �˳���ѯ */

		printf("enter choice:");				/* ������ʾ */
		scanf("%d",&choice);					/* �����û�����ı�� */

		/* �������0����ǰ����forѭ�� */
		if(choice==0)
			break;								/* �˴���break����forѭ�� */
		/* ��������ı�ţ�����Ӧ�ļ۸񸳸�price */
		switch(choice)
		{
			case 1:price=3.0;break;				/* ��break����switch��䣬��ͬ */
			case 2:price=2.5;break;
			case 3:price=4.0;break;
			case 4:price=3.5;break;
			default:price=0.0;break;
		}
		
		/* �����Ʒ�ļ۸� */
		printf("price=%0.1f\n",price);
	}											/* for��ѭ���������� */

	printf("thanks! \n");						/* ������ѯ��лл�û�ʹ�� */

	return 0;
}