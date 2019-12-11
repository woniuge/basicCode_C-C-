

#include <iostream.h>
#include <string.h>

//using namespace std;

template<class T>
T min(T& ra, T& rb)
{
	return (ra < rb ? ra : rb);
}

char* min(char* s1, char* s2)
{
	return (strcmp(s1,s2) >= 0 ? s2 : s1);
}

int main()
{
/*	cout << "Min(3 , 5) is "
		 << min(3,5) << endl;*/
	cout << min("ab","ac") << endl; 
}



