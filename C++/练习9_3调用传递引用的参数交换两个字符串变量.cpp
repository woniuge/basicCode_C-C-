//��ϰ9_3���ô������õĲ�����ʵ�������ַ��������Ľ�����
//���翪ʼ��
//char* ap = "hello";
//char* bp = "how are you?";
//�����Ľ��ʹ��ap��bpָ������ݷֱ�Ϊ��
//ap:	"how are you?"
//bp:	"hello"
#include <iostream.h>
void Swap(char*&, char*&);

int main(void)
{
	char* ap =  "hello";
	char* bp = "how are you?";

	cout << "before swap:" << endl;
	cout << "ap:" << ap << endl
		 << "bp:" << bp << endl;
	
	Swap(ap, bp);

	cout << "after swap:" <<endl;
	cout << "ap:" << ap << endl
		 << "bp:" << bp << endl;
}
  
void Swap(char*& rap, char*& rbp)
{
	char* temp;

	temp = rap;
	rap = rbp;
	rbp = temp;
}
