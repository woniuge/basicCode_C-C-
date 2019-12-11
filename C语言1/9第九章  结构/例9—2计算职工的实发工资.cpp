/* 计算职工的实发工资 */
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

	printf("请输入职工人数n:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		printf("请输入第%d个职工的信息:",n);
		scanf("%d%s%f%f%f",&e.num,e.name,&e.jbgz,&e.jj,&e.bx);
		e.sfgz=e.jbgz+e.jj-e.bx;
		printf("编号:%d 姓名:%s 实发工资:%.2f\n",e.num,e.name,e.sfgz);
	}

	return 0;
}