#include <iostream>
#include <fstream>
#include "student.h"
#include "master.h"
#include <cstring>
using namespace std;

int main()
{
	ifstream fin("D:\\DevelopmentSoftware\\Microsoft Visual Studio 2010\\Projects\\C++\\ch19_16\\abc.txt");

	char sFirst[10];
	char sLast[10];
	unsigned int uid;
	float nGrade;
	char type;
	char name[20];
	Student* pS;
	int i=0;

	fin>>sLast>>sFirst>>uid>>nGrade>>type;

	while(!fin.eof())
	{
		strcpy(name,strcat(sLast,""));
		strcpy(name,strcat(name,sFirst));

		pS=new MasterStudent(name,uid,nGrade,type);
		cout<<"student #"<<++i<<":"<<*pS;
		delete pS;

		name[0]=0;	//½«nameÖÐÄÚÈÝÖÃ¿Õ´®
		fin>>sLast>>sFirst>>uid>>nGrade>>type;
	}


	/*student s1("dill arnson",12567,3.5);
	masterstudent s2("welch shammas",12667,4.1,'a');
	masterstudent s3("portel braumbel",12579,3.8,'b');

	out <<s1;
	out <<s2;
	out <<s3;*/
}