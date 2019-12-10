#include <iostream>
#include "master.h"
using namespace std;

void MasterStudent::display(ostream& out)
{
	Student::display(out);
	out<<","<<type;
}