/* ��һ��һԪƱ��1�֣�2�ֺ�5�ֵ�Ӳ�ң����ٸ�һö�������м��ֻ�����
ÿ�ֻ�����1�֣�2�ֺ�5�ֵ�Ӳ�Ҹ���ö�� */
#include <stdio.h>

int main(void)
{
	int coin1,coin2,coin5,count;

	count=0;
	for(coin5=1;coin5<=19;coin5++)
		for(coin2=1;coin2<=47;coin2++)
			for(coin1=1;coin1<=93;coin1++)
				if(5*coin5+2*coin2+coin1==100)
				{
					printf("coin1=%-2d,coin2=%-2d,coin5=%-2d\n",coin1,coin2,coin5);
					count++;
				}

	printf("count=%d\n",count);

	return 0;
}