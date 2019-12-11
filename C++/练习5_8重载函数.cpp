//编写程序，其中包含三个重载的display（）函数。
//第一个函数输出一个double值，前面用字符串“A double：”引导；
//第二个函数输出一个int值，前面用字符串“A int：”引导；
//第三个函数输出一个char值，前面用字符串“A char：”引导。
//在主函数中，分别用double，float，int，char 和 short 型变量去调用display（）函数，并对结果做简要说明。

#include <iostream.h>

void display(double d);
void display(int m);
void display(char c);

int main(void)
{
	double d = 12.7;
	float f = 9.0;
	int n = 7;
	char ch = 'a';
	short s = 70;

	display(d);
	display(f);
	display(n);
	display(ch);
	display(s);
}

void display(double d)
{ 
	cout << "A double: " << d <<endl; 
}
void display(int m)
{ 
	cout << "A int: " << m <<endl; 
}
void display(char c)
{ 
	cout << "A char: " << c <<endl;
}