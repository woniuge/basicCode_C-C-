//将常数e（2.718281828）作为常量定义，然后输出其10位有效位数的浮点数、
//定点方式和8位小数位表示的数，以及指数形式和8位小数位表示的数。

#include <iostream.h>
#include <iomanip.h>

const double e = 2.718281828;

int main(void)
{
	cout << "1#10位有效位数的浮点数:" << setprecision(10) << e <<endl
		 << "2#定点方式和8位小数位表示的数:" << setiosflags(ios::fixed)
		 << setprecision(8) << e <<endl
		 << "3#指数形式和8位小数位表示的数:" << setiosflags(ios::scientific)
		 << setprecision(8) << e <<endl;
	
	cout << setprecision(6);		
}

