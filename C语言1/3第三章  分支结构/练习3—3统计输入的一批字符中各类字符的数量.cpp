/* ͳ�������n���ַ���Ӣ���ַ����ո��س��������ַ��������ַ����и����ַ������� */
#include <stdio.h>

int main(void)
{
	int i,n,letter,blank,digit,other;
	char ch;

	printf("enter n:");
	scanf("%d",&n);
	printf("enter %d characters:",n);
	ch=getchar();

	letter=blank=digit=other=0;
	for(i=1;i<=n;i++)
	{
		ch=getchar();
		if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
			letter++;
		else if(ch==' '||ch=='\n')
			blank++;
		else if(ch>='0'&&ch<='9')
			digit++;
		else
			other++;
	}

	printf("letter=%d,blank=%d,digit=%d,other=%d\n",letter,blank,digit,other);

	return 0;
}