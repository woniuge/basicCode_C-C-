#include <iostream.h>
#include <math.h>

double max(double x,double y);

int main(){
	double a,b,c;
	cout << "input two numbers:\n";
	cin >>a>>b;

	c=max(a,b);
	cout<<"the squart of maxium="<<sqrt(c)<<endl;
}

double max(double x,double y){
	if(x>y)
		return x;
	else
		return y;
}