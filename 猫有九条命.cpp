#include <signal.h>
#include <Windows.h>
#include <iostream>
using namespace std;
void cs(int sig)
{
  if(sig == SIGINT)
  {
      cout<<"�㰴����ctrl+c����ɱ������"<<endl;
      signal(SIGINT, cs);
      return;
  }
}
int main()
{
    char ch;
	cout<<"è�о�������ÿ��һ��ctrl+c��è����һ��"<<endl;
    signal(SIGINT, cs);  /*ע��ctrl+c�źŲ�����*/
    int n = 9;
    while(n > 0)
    {
        cin>>ch;
        Sleep(10);
        if(cin.fail())
        {
            cin.clear();
            cin.sync();
        }
        n--;
    }
return 0;
}

