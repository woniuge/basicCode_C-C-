/* Ƥ���height�׵ĸ߶��������£����غ󷴵���ԭ�߶ȵ�һ�룬
�����£��ٷ�������˷�����Ƥ���ڵ�n�η������ʱ���ڿ��о�
����·���Ƕ����ף���n�η����ĸ߶��Ƕ��٣����������һλС
���� */
#include <stdio.h>

int main(void)
{
	int i,n;
	double distance,height;

	printf("input height:");
	scanf("%lf",&height);
	printf("input n:");
	scanf("%d",&n);

	distance=height;
	for(i=1;i<=n;i++)
	{
		height=height/2;
		distance=distance+height*2;
	}

	printf("distance=%.1lf\nheight=%.1lf\n",distance,height);

	return 0;
}
