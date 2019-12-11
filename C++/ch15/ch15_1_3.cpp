
//ch15_1_3

#include <iostream.h>

class A
{
public:
	A(int i = 0):num(i)
	{
		cout << "create one A\n";
		num = i;
		counter++;
		cout << "num = " << num << "\tcounter = " << counter << endl;
	}
	~A()
	{
		cout << "destruct one A\n";
		counter--;
		cout << "num = " << num << "\tcounter = " << counter << endl;
	}
	static int get_counter();
protected:
	int num;
	static int counter;
};

int A::counter = 0;

int main()
{
	A a1(3);
	A a2(5);
	A a3(6);
}