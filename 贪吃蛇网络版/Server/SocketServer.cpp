/*程序名：SocketServer.cpp
*功能：完成服务器端Socket类的实现
*作者：袁海峰
*日期：2017年11月11日
*/

#include "SocketServer.h"
#include <cstdio>
#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>

using namespace std;

#define LENGTH_OF_LISTEN_QUEUE 20


int SocketServer::serverBindAndListen(int portNumber) {
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(portNumber);

    //创建基于TCP协议的socket
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        cerr <<"Create Socket Failed!" << endl;
        _exit(1);
    }
    {
        int opt = 1;
        setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    }

    //把socket fd和socket地址结构联系起来
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr))) {
        cerr << "Server bind port:  "<<portNumber<< " failed!"<<endl;
        _exit(1);
    }
    //监听客户端的请求
    if (listen(server_socket, LENGTH_OF_LISTEN_QUEUE)) {
        cerr << "Server Listen Failed!"<<endl;
        _exit(1);
    }
    cout << "Server starts listening to port "<< portNumber << endl;
    return 0;
}

int SocketServer::serverAccept() {
    //定义客户端的socket地址结构client_addr
    struct sockaddr_in client_addr;
    socklen_t length = sizeof(client_addr);
    //接收一个到server_socket代表的socket的一个连接
    //如果没有连接请求，就等待到有连接请求——这是accept函数的特性
    //accept函数返回一个新的socket，这个socket用于同连接到的客户通信
    int new_server_socket = accept(server_socket, (struct sockaddr *) &client_addr, &length);
    if (new_server_socket < 0) {
        cerr << "Server accept failed" << endl;
    }
    cout << "Server accpet a new connection request. A corresponding Unix-fd number " << new_server_socket <<" is created." << endl;
    return new_server_socket;
}

void SocketServer::serverStopService() {
    close(server_socket);
    cout << "server_socket closed." << endl;
}
