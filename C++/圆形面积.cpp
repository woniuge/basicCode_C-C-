//��Ŀ��ʹ������������дһ����Բ������ĳ��򣬷ֱ�����뾶Ϊ1.5��2��Բ�������

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
