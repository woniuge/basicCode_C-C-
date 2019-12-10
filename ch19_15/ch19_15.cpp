#include <fstream>
#include "student.h"
#include "master.h"
using namespace std;

int main()
{
	ofstream out("D:\\DevelopmentSoftware\\Microsoft Visual Studio 2010\\Projects\\C++\\ch19_15\\abc.txt");

	Student s1("Dill Arnson",12567,3.5);
	MasterStudent s2("Welch Shammas",12667,4.1,'A');
	MasterStudent s3("Portel Braumbel",12579,3.8,'B');

	out <<s1;
	out <<s2;
	out <<s3;
}