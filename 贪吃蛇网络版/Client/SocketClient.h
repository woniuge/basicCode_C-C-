/*程序名：SocketClient.h
*功能：完成客户端Socket的类声明
*作者：袁海峰
*日期：2017年11月11日
*/

#ifndef CLIENTSERVER01_SOCKETCONNECTWIZ_H
#define CLIENTSERVER01_SOCKETCONNECTWIZ_H

#include <cstdio>

class SocketClient {
public:
    int clientGetConnection(const char * serverIP, int portNumber);
    void clientCloseConnection();
public:
    int client_socket;
};


#endif //CLIENTSERVER01_SOCKETCONNECTWIZ_H
