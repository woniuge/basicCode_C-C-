/* ������ָ����Ϊ�����ĺ�����ģ����è��̫�ӵĹ��� */
#include <stdio.h>
#define CIVET 0		/* ������è��ֵΪ0 */
#define PRINCE 1	/* �������ӵ�ֵΪ1 */
void replace1(int baby);
void replace2(int *baby);
void display(int who);

int main(void)
{
	int baby;		/* ����baby��������ĺ��� */
	baby=PRINCE;	/* �ճ���ʱ������ */

	printf("before change,baby is ");	/* �������ǰ����Ϣ */
	display(baby);

	replace1(baby);		/* ���ú���replace1��ʵʩ��è��̫�ӵ�һ���ж� */

	printf("\n");
	printf("after first action,baby is ");	/* �����һ���ж������Ϣ */
	display(baby);

	replace2(&baby);	/* ���ú���replace2��ʵʩ��è��̫�ӵڶ����ж� */

	printf("\n");
	printf("after second action,baby is ");		/* ����ڶ����ж������Ϣ */
	display(baby);

	printf("\n");

	return 0;
}

void replace1(int baby)
{
	baby=CIVET;
}

void replace2(int *baby)
{
	*baby=CIVET;
}

void display(int who)
{
	if(who==CIVET)
		printf("��è");
	else
		if(who==PRINCE)
		printf("����");
}