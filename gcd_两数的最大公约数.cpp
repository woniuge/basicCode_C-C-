#include<iostream>
using namespace std;

int gcd(int,int);
int main()
{
	int p,q;
	cin >> p>>q;
	cout << "the gcd of "<<p<<" and "<<q<<" is "<<gcd(p,q)<<endl;
}

int gcd(int m,int n)
{
	if(n == 0)
		return m;
	else
		return gcd(n,m%n);
}