/* ���100��200֮�������������ÿ�����8�� */
#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,m,count;

	count=0;
	for(m=100;m<=200;m++)
	{
		for(i=2;i<=sqrt(m);i++)
			if(m%i==0)break;
		if(i>sqrt(m))
		{
			printf("%6d",m);
			count++;
			if(count%8==0)
				printf("\n");
		}
	}

	printf("\n");

	return 0;
}