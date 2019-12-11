#include <stdio.h>

void hanoi(int n,int a,int b,int c);
void move(int a,int b);

int main(void)
{
	int a,b,c;
	int i;
	int n;

	a=1;
	b=2;
	c=3;

	printf("ÇëÊäÈëººÅµËþµÄÅÌÊý£º");
	scanf("%d",&n);

	hanoi(n,a,b,c);

	return 0;
}
void hanoi(int n,int a,int b,int c)
{
	if(n==1)
		move(a,b);
	else
	{
		hanoi(n-1,a,c,b);
		move(a,b);
		hanoi(n-1,c,b,a);
	}
}

void move(int a,int b)
{
	printf("%d--->%d\n",a,b);
}