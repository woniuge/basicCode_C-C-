/*程序名：NumberGuess
*功能：完成猜数字游戏
*作者：袁海峰
*日期：2017年11月11日
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int number,guess;
    bool running=true;

    srand(time(NULL));//设置随机数种子，使每次运行获取到的随机数值不同
    number = rand()%10+1;//获取1～100的随机数

    cout << "Welcome to Guess a number game!" << endl << endl;
    while(running){
        do{
            cout <<"Please import a integer between 1 and 10:"<<endl;
            cin >> guess;
        }while(guess<1 || guess > 10);

        if(guess==number){
            cout << "Congratulations,you guessed it!" << endl;
            running = false;
        }
        else if(guess < number)
            cout << "No,it is a little higher." << endl;
            else
                cout << "No,it is a little lower." << endl;
    }
    cout << "Success"<< endl;
    return 0;
}
