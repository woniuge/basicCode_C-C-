//ȡԲ����Ϊ3.1415926���ֱ�����뾶Ϊ40��928.335����Բ�����
//Ҫ������ݰ����10λ����������Բ���ʺͰ뾶��������������

#include <iostream.h>
#include <iomanip.h>	//Ҫ�õ���ʽ���Ʒ�

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
