/* ���ƴ������һ���Ը��������ĳɼ���ѡ����߷�,��while���ʵ�� */
#include <stdio.h>

int main(void)
{
	double mark,max;

	printf("enter marks:");
	scanf("%lf",&mark);

	if(mark<0);
	else
	{
		max=mark;
		while(mark>=0)
		{
			if(max<mark)
			max=mark;
			scanf("%lf",&mark);
		}

		printf("max=%.2lf\n",max);
	}

	return 0;
}