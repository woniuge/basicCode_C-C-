#include<iostream>
using namespace std;
#include<string>
#ifndef STUDENT
#define STUDENT

//大学生类
class Student
{
	public:
		Student(char* pS,unsigned num,float g)
		{
			strcpy_s(pName,pS);
			uID=num;
			grade=g;
		}
		virtual void display(ostream& out);
	protected:
		char pName[20];
		unsigned int uID;
		float grade;
};
ostream& operator<<(ostream& out,Student& st);
#endif