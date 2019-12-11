//题目：使用内联函数编写一个求圆形面积的程序，分别输出半径为1.5和2的圆形面积。

#include <iostream.h>
#define PI 3.1415926

inline double area(double r);


int main(void)
{
	int i;
	double r;

	for(i = 0 ; i <= 1 ; i++){
		cout << "Enter the radius of the circular:";
		cin >> r;

		cout << "The area of the circular is " << area(r) << endl;
	}
}

inline double area(double r)
{
	return PI*r*r;
}
