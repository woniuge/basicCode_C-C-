/* ����ְ����ʵ������ */
#include <stdio.h>
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
		e.sfgz=e.jbgz+e.jj-e.bx;
		printf("���:%d ����:%s ʵ������:%.2f\n",e.num,e.name,e.sfgz);
	}

	return 0;
}