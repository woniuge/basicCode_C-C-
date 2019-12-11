#include <iostream.h>

#define NL cout << endl
#define CO(val) cout << #val << " = " << val << '\t'
#define COUT1(x) CO(x), NL
#define COUT2(x , y) CO(x) , COUT1(y)

int main()
{
	for(int x = 0 , int y = 1000 ; y > 1 ; x++ , y /= 10 )
		COUT2(x,y);
}
