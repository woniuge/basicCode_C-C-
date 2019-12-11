//用sizeof操作符，求出表2-2中各数据类型的字节长度
#include <iostream.h>

int main(void)
{
	cout << "size of char                " << sizeof(char) << "byte" << endl
		 << "size of unsigned char       " << sizeof(unsigned char) << "byte" << endl
		 << "size of signed char         " << sizeof(signed char) << "byte" << endl
		 << "size of int                 " << sizeof(int) << "byte" << endl
		 << "size of unsigned int        " << sizeof(unsigned int) << "byte" << endl
		 << "size of signed int          " << sizeof(signed int) << "byte" << endl
		 << "size of short int           " << sizeof(short int) << "byte" << endl
		 << "size of unsigned short int  " << sizeof(unsigned short int) << "byte" << endl
		 << "size of signed short int    " << sizeof(signed short int) << "byte" << endl
		 << "size of long int            " << sizeof(long int) << "byte" << endl
		 << "size of signed long int     " << sizeof(signed long int) << "byte" << endl
		 << "size of unsigned long int   " << sizeof(unsigned long int) << "byte" << endl
		 << "size of float               " << sizeof(float) << "byte" << endl
		 << "size of double              " << sizeof(double) << "byte" << endl
		 << "size of long double         " << sizeof(long double) << "byte" << endl;
}