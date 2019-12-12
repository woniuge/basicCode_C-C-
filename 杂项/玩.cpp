#include <stdio.h>

int main()
{
	char ch;
	
	ch='132';
	printf("%c\n",ch);

	ch='\x41';
	printf("%c\n",ch);
	
	ch='\018';
	printf("%c\n",ch);

	ch='1234';
	printf("%c\n",ch);

	return 0;
}