//练习9_3调用传递引用的参数，实现两个字符串变量的交换。
//例如开始：
//char* ap = "hello";
//char* bp = "how are you?";
//交换的结果使得ap和bp指向的内容分别为：
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
