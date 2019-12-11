/* 利用结构变量求解两个复数之积 */
#include <stdio.h>
struct fushu
{
	int shibu;
	int xubu;
};

int main(void)
{
	struct fushu a,b,result;
	
	printf("输入a1,a2,b1,b2:");
	scanf("%d%d%d%d",&a.shibu,&a.xubu,&b.shibu,&b.xubu);

	result.shibu=a.shibu*b.shibu-a.xubu*b.xubu;
	result.xubu=a.shibu*b.xubu+a.xubu*b.shibu;

	if(a.xubu>=0&&b.xubu>=0)
		printf("(%d+%di)*(%d+%di)=",a.shibu,a.xubu,b.shibu,b.xubu);
	else if(a.xubu>=0&&b.xubu<0)
		printf("(%d+%di)*(%d%di)=",a.shibu,a.xubu,b.shibu,b.xubu);
	else if(a.xubu<0&&b.xubu>=0)
		printf("(%d%di)*(%d+%di)=",a.shibu,a.xubu,b.shibu,b.xubu);
	else 
		printf("(%d%di)*(%d%di)=",a.shibu,a.xubu,b.shibu,b.xubu);
	if(result.xubu>=0)
		printf("%d+%di\n",result.shibu,result.xubu);
	else
		printf("%d%di\n",result.shibu,result.xubu);

	return 0;
}