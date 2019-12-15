/*程序名：SocketClient.cpp
*功能：完成客户端Socket的类实现
*作者：袁海峰
*日期：2017年11月11日
*/


#include "SocketClient.h"
#include <cstdio>
#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <cstdlib>
#include <unistd.h>
#define LENGTH_OF_LISTEN_QUEUE 20

int SocketClient::clientGetConnection(const char * serverIP, int portNumber) { //创建socket fd给用户, 好像一个文件指针似的可以直接使用
    //创建用于TCP协议的client_socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);  //创建socket
    if (client_socket < 0) {
        printf("Create Socket Failed!\n");
        exit(1);
    }

    /*server_addr*/
    //设置一个socket地址结构server_addr，代表服务器的internet地址，端口
    struct sockaddr_in server_addr;  // 要连接的服务器的地址
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    if (inet_aton(serverIP, &server_addr.sin_addr) == 0) { //inet_aton: 把arg1转化为二进制, 然后交付给arg2, 返回值为
        printf("Server IP Address Error!\n");
        exit(1);
    }
    server_addr.sin_port = htons(portNumber);
    socklen_t server_addr_length = sizeof(server_addr);

    //向服务器发起连接
    if (connect(client_socket, (struct sockaddr *) &server_addr, server_addr_length) < 0) {  //使得刚创立好的fd成为客户端与服务器交流的接口
        printf("Can Not Connect To %s!\n", serverIP);
        exit(1);
    }
    return 0;
}

void SocketClient::clientCloseConnection() {
    close(client_socket);
    printf("client_socket closed.\n");
}
