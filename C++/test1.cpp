#include <iostream.h>


#define NL cout << endl
#define CO(val) cout << #val << " = " << val << '\t'
#define COUT1(x) CO(x), NL
#define COUT2(x , y) CO(x) , COUT1(y)

#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main()
{
	int a = 1, b = 0;

//	COUT2(MAX(a++,b),a);
//	COUT2(MAX(a++,b+10),a);
	COUT2(MAX(a,"Hello"),a);

//	cout << #(MAX(a++,b)) << " = " << MAX(a++,b) << 
}
