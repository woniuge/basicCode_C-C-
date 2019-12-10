#include <signal.h>
#include <Windows.h>
#include <iostream>
using namespace std;
void cs(int sig)
{
  if(sig == SIGINT)
  {
      cout<<"你按下了ctrl+c，并杀死了它"<<endl;
      signal(SIGINT, cs);
      return;
  }
}
int main()
{
    char ch;
	cout<<"猫有九条命，每按一次ctrl+c，猫就死一次"<<endl;
    signal(SIGINT, cs);  /*注册ctrl+c信号捕获函数*/
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

