/*程序名：SocketServer.h
*功能：完成服务器端Socket类的声明
*作者：袁海峰
*日期：2017年11月11日
*/

#ifndef CLIENTSERVER01_SOCKETCONNECTWIZ_H
#define CLIENTSERVER01_SOCKETCONNECTWIZ_H

#include <cstdio>

class SocketServer {
public:  //server
    int serverBindAndListen(int portNumber);
    int serverAccept();
    void serverStopService();

public:
    int server_socket;
};


#endif //CLIENTSERVER01_SOCKETCONNECTWIZ_H
