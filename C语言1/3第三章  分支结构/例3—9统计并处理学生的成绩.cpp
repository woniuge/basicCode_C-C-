/* ����һ��ѧ���ĳɼ�������ƽ���֣���ͳ�Ʋ�����ɼ��ĸ��� */
#include <stdio.h>

int main(void)
{
	int i,n,failure;
	double grade,total;

	printf("enter n:");
	scanf("%d",&n);
	
	total=failure=0;
	for(i=1;i<=n;i++)
	{
		printf("enter grade #%d:",i);
		scanf("%lf",&grade);
		total=total+grade;
		if(grade<60)
		{
			failure++;
		}
	}
	printf("grade average=%.2f\n",total/n);
	printf("number of failures=%d\n",failure);

	return 0;
}