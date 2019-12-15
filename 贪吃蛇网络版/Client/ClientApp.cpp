/*程序名：ClientApp.cpp
*功能：完成客户端猜数字游戏的输入工作
*作者：袁海峰
*日期：2017年11月11日
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "SocketClient.h"
#include <iostream>

using namespace std;

#define HELLO_WORLD_SERVER_PORT    6666
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512

int clientWork(SocketClient client) {
    char ans[100];
    //连接成功后，让用户输入用户名
    char name[FILE_NAME_MAX_SIZE + 1];
    bzero(name, FILE_NAME_MAX_SIZE + 1);
    cout << "Please Input your name: "<<endl;
    cin >> name;
    send(client.client_socket, name, strlen(name), 0);
    char buffer[BUFFER_SIZE];

    bzero(buffer, BUFFER_SIZE);      //接收验证问题，模拟验证码
    recv(client.client_socket, buffer, BUFFER_SIZE, 0);
    cout << buffer;// 打印服务器的问题
    do {
        bzero(ans, sizeof(ans));  // 清空ans
        cin >> ans;
        send(client.client_socket, ans, strlen(ans), 0);  //往服务端发送答案
        bzero(buffer, BUFFER_SIZE); //发送完毕清空buffer
        recv(client.client_socket, buffer, BUFFER_SIZE, 0);
        cout << buffer;
    } while (strcmp(buffer, "Answer is right") != 0);
    cout << "!" <<endl;

    cout << "Welcome to Guess a number game!" << endl;

    bool running=true;
    int guess[1];
    while(running){
        do{
            cout <<"Please import a integer between 1 and 100:"<<endl;
            cin >> guess[0];
        }while(guess[0]<1 || guess[0] > 100);
        send(client.client_socket, guess, sizeof(guess), 0);
        bzero(buffer, BUFFER_SIZE); //发送完毕清空buffer
        recv(client.client_socket, buffer, BUFFER_SIZE, 0);
        if (strcmp(buffer, "success") == 0){     //如果服务端回复的消息为“成功”，则返回
            cout << "Congratulations,you guessed it!" << endl;
            running = false;
            return 0;
        }
        else if(strcmp(buffer, "higher") == 0)
            cout << "No,it is a little higher." << endl;
            else
                cout << "No,it is a little lower." << endl;
    }
}

int main(int argc, char **argv) {
    /*输入参数校验*/
    if (argc != 2) {
        printf("Usage: %s ServerIP\n", argv[0]);  //提示输入错误, 应该是Usage：./programName ServerIP
        exit(1);
    }
    SocketClient client;
    client.clientGetConnection(argv[1], HELLO_WORLD_SERVER_PORT);
    clientWork(client);
    client.clientCloseConnection();
    return 0;
}
