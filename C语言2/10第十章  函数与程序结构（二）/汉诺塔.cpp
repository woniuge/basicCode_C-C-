#include <stdio.h>

void hanoi(int n,char x,char y,char z)
{
	if(n==1)
	{
		printf("------ disk [%d] from %c ---> %c \n",n,x,y);
		return;
	}

	hanoi(n-1,x,z,y);
	printf("TOP--- disk [%d] from %c ---> %c \n",n,x,y);
	hanoi(n-1,z,y,x);
}

int main(void)
{
	printf("Hanoi!-----------------\n");
	hanoi(3,'a','b','c');
	printf("Hanoi!-----------------\n");
	return 0;

	/*  char buf[2][10]={"hanoi","hi"};
	
	  char buf[2][10];


		strcpy(buf[0],"hanoi");

  buf[1]="hi";//ÕâÊÇ´íµÄ

  */
}