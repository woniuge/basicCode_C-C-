/* �Ӽ�������һ��ѧ���ĳɼ�������ƽ���� */
#include <stdio.h>

int main(void)
{
	int num;
	double grade,total;

	printf("enter grade:");
	scanf("%lf",&grade);

	num=total=0;
	while(grade>=0)
	{
		total=total+grade;
		num++;
		scanf("%lf",&grade);
	}
	if(num!=0)
		printf("grade average is %.2f\n",total/num);
	else
		printf("grade average is 0\n");

	return 0;
}