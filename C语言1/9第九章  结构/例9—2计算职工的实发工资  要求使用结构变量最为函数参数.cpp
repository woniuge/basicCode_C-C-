/* ����ְ����ʵ������  Ҫ��ʹ�ýṹ������Ϊ�������� */
#include <stdio.h>
float count_sfgz(struct employee m);
struct employee
{
	int num;
	char name[20];
	float jbgz,jj,bx,sfgz;
};

int main(void)
{
	int i,n;
	struct employee e;

	printf("������ְ������n:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("�������%d��ְ������Ϣ:",n);
		scanf("%d%s%f%f%f",&e.num,e.name,&e.jbgz,&e.jj,&e.bx);
		e.sfgz=count_sfgz(e);
		printf("���:%d ����:%s ʵ������:%.2f\n",e.num,e.name,e.sfgz);
	}

	return 0;
}

float count_sfgz(struct employee m)
{
	return m.jbgz+m.jj-m.bx;
}