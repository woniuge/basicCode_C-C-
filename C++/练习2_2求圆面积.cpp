//取圆周率为3.1415926，分别输入半径为40和928.335，求圆面积，
//要求各数据按域宽10位输出，先输出圆周率和半径，再输出其面积。

#include <iostream.h>
#include <iomanip.h>	//要用到格式控制符

const double pi = 3.1415926;

int main()
{
	int i;
	double r;

	for(i = 0 ; i <= 1 ; i++){
		cout << "Enter the radius of the circular:";
		cin >> r;

		cout << setw(10) << pi<< endl
			 << "Radius = " << setw(10) << r << endl
			 << "The area of the circular is " << setw(10) << pi*r*r << endl;
	}
}
