/* ����һ��ѧ���ĳɼ�������ƽ���֣���ͳ�����м�������� */
#include <stdio.h>

int main(void)
{
	int i,n,pass;
	double grade,total;

	printf("enter n:");
	scanf("%d",&n);

	total=pass=0;
	for(i=1;i<=n;i++)
	{
		printf("enter grade #%d:",i);
		scanf("%lf",&grade);
		total=total+grade;
		if(grade>60)
		{
			pass++;
		}
	}

	printf("grade average=%.2f\n",total/n);
	printf("number of passes=%d\n",pass);

	return 0;
}