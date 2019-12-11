//练习2_6_4调用函数求三角形面积
#include <iostream.h>
#include <math.h>
#include <iomanip.h>

float area(float a,float b,float c);

int main(void)
{
	float a,b,c;

	cout << "please input 3 sides of one triangle:" << endl;
	cin >> a >> b >> c;

	cout << "a = " 
		 << setiosflags(ios::fixed) << setprecision(2) << setw(7) << a
		 << ",b = " 
		 << setiosflags(ios::fixed) << setprecision(2) << setw(7) << b
		 << ",c = " 
		 << setiosflags(ios::fixed) << setprecision(2) << setw(7) << c << endl;

	cout << "area of triangle is "
		 << setiosflags(ios::fixed) << setprecision(5) << setw(10) << area(a,b,c) << endl;

	cout << setprecision(6);
}

float area(float a,float b,float c)
{
	int s;

	s = (a+b+c)/2;

	return sqrt(s*(s-a)*(s-b)*(s-c));	
}