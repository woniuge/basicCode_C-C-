/* ͳ���ַ��������ո��س��������ַ��������ַ� */
#include <stdio.h>

int main(void)
{
	int  i,n,blank,digit,other;							/* ����3�������ֱ���ͳ�ƽ�� */
	char ch;

	printf("enter n:");									/* ��ʾ����ͳ������n */
	scanf("%d",&n);
	printf("enter %d characters:\n",n);					/* ������ʾ */
		ch=getchar();									/* ����һ���ַ� */

	blank=digit=other=0;								/* �ô��ͳ�ƽ����3�������ĳ�ֵΪ�� */
	for(i=1;i<=n;i++)									/* ѭ��ִ����n�� */
	{
		ch=getchar();									/* ����һ���ַ� */
		/* ��switch��������Ӧ��break */
		switch(ch)
		{
			case' ':										/* ����Ϊ�գ���ע��ո�ı�ʾ */
			case'\n':
				blank++;								/* �����������ʽ' '��'\n'���ø����� */
				break;									/* ����switch��� */
			case'0':case'1':case'2':case'3':case'4':
			case'5':case'6':case'7':case'8':case'9':
				digit++;								/* 10���������ʽ'0'~'9'���ø����� */
				break;									/* ����switch��� */
			default:
				other++;								/* �ۼ������ַ� */
				break;									/* ����switch��� */
		}
	}

	printf("blank=%d,digit=%d,other=%d\n",blank,digit,other);

	return 0;
}