//ThePerimeterAndAreaOfTriangle

#include <iostream.h>
#include <math.h>

class Triangle
{
public:
	Triangle(double ,double ,double );		//The constructor declaration
	double GetPerimeter();
	double GetArea();
	void display();
protected:
	double a;
	double b;
	double c;
};

Triangle::Triangle(double x,double y,double z)	//The constructor definition
{
	a = x;
	b = y;
	c = z;
}

double Triangle::GetPerimeter()
{
	return a+b+c;
}

double Triangle::GetArea()
{
	double s = (a+b+c)/2;

	return sqrt(s*(s-a)*(s-b)*(s-c));
}

void Triangle::display()
{
	cout << "Triangle:" << "a = " << a << '\t' << "b = " << b << '\t' << "c = " << c << endl;
	cout << "Perimeter:" << GetPerimeter() << endl;
	cout << "Area:" << GetArea() << endl;
}

int main()
{
	Triangle T(3,4,5);
	T.display();
}