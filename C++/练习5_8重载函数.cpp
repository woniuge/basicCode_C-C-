//��д�������а����������ص�display����������
//��һ���������һ��doubleֵ��ǰ�����ַ�����A double����������
//�ڶ����������һ��intֵ��ǰ�����ַ�����A int����������
//�������������һ��charֵ��ǰ�����ַ�����A char����������
//���������У��ֱ���double��float��int��char �� short �ͱ���ȥ����display�������������Խ������Ҫ˵����

#include <iostream.h>

void display(double d);
void display(int m);
void display(char c);

int main(void)
{
	double d = 12.7;
	float f = 9.0;
	int n = 7;
	char ch = 'a';
	short s = 70;

	display(d);
	display(f);
	display(n);
	display(ch);
	display(s);
}

void display(double d)
{ 
	cout << "A double: " << d <<endl; 
}
void display(int m)
{ 
	cout << "A int: " << m <<endl; 
}
void display(char c)
{ 
	cout << "A char: " << c <<endl;
}