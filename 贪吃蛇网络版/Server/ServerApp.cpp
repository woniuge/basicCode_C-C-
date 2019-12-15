/*程序名：SocketApp.cpp
*功能：完成服务器端猜数字游戏的功能
*作者：袁海峰
*日期：2017年11月11日
*/

//#include <netinet/in.h>
#include <cstdio>
#include <cstring>
#include <unistd.h>
//#include <sys/wait.h>
#include "SocketServer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define HELLO_WORLD_SERVER_PORT 6666 //使用的端口号
#define BUFFER_SIZE 1024
#define FILE_NAME_MAX_SIZE 512


void clearBuffer(char *buffer) {
    bzero(buffer, BUFFER_SIZE);
}

/*
 * 需要使用的recv和send操作范例:
 * length = recv(new_server_socket, buffer, BUFFER_SIZE, 0);  // received client-msg is stored in buffer
 * length = send(new_server_socket, buffer, sizeof(buffer), 0);  // send server-msg in buffer to client
 * 我们总是默认client发第一个消息(比如发用户名过来), 然后server进行答复或者提问
 * */
int serverWork(int new_server_socket) {
    socklen_t length = 0;
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);
    //默认是client发第一个消息, 然后server进行答复或者提问
    length = recv(new_server_socket, buffer, BUFFER_SIZE, 0);  //接收客户端的用户名，received msg is stored in buffer
    if (length < 0) {
        cerr << "Server receive  the username failed" << endl;
    }
    char name[FILE_NAME_MAX_SIZE + 1];  // +1 为了放'\0'
    bzero(name, FILE_NAME_MAX_SIZE + 1);
    strncpy(name, buffer,
            strlen(buffer) > FILE_NAME_MAX_SIZE ? FILE_NAME_MAX_SIZE : strlen(buffer));  //只复制放得下的部分
    cout << name << " is requesting..." << endl;
    bzero(buffer, BUFFER_SIZE);
    strcpy(buffer, "Please answer the question: 3 + 5 = ?\nInput your answer:\n");
    cout << "Sending question to the client..." << endl;
    send(new_server_socket, buffer, sizeof(buffer), 0);//发送验证问题给客户端
    bzero(buffer, BUFFER_SIZE);
    recv(new_server_socket, buffer, BUFFER_SIZE, 0);//接收客户端的答案
    while (strcmp(buffer, "8") ) {
            char ans[5];
            strcpy(ans, buffer);
            cout <<"Answer: " << buffer << " is wrong!"<<endl;
            bzero(buffer, BUFFER_SIZE);
            sprintf(buffer, "Your answer:%s is wrong. Please send a new one: \n", ans);
            send(new_server_socket, buffer, sizeof(buffer), 0);//告诉用户答案错误
            bzero(buffer, BUFFER_SIZE);
            recv(new_server_socket, buffer, BUFFER_SIZE, 0);
        }
        cout << "Answer " << buffer << " is right!" << endl;
        bzero(buffer, BUFFER_SIZE);
        strcpy(buffer, "Answer is right");
        send(new_server_socket, buffer, sizeof(buffer), 0);  // 告诉用户答案正确
        bzero(buffer, BUFFER_SIZE);

        char number[1],guess[1];
        bool running=true;

        srand(time(NULL));//设置随机数种子，使每次运行获取到的随机数值不同
        number[0] = rand()%100+1;//获取1～100的随机数

        while(running){
        recv(new_server_socket, buffer, BUFFER_SIZE, 0);
        strcpy(guess,buffer);

        if(guess[0]==number[0]){
            strcpy(buffer, "success");
            send(new_server_socket, buffer, sizeof(buffer), 0);
            bzero(buffer, BUFFER_SIZE);
            running = false;
        }
        else if(guess[0] < number[0]){
            strcpy(buffer, "higher");
            send(new_server_socket, buffer, sizeof(buffer), 0);
            bzero(buffer, BUFFER_SIZE);
        }
            else{
            strcpy(buffer, "lower");
            send(new_server_socket, buffer, sizeof(buffer), 0);
            bzero(buffer, BUFFER_SIZE);
            }
    }

    return 0;
}

void reaper(int sig) {
    int status;
    //调用wait3读取子进程的返回值, 使僵死状态的子进程彻底释放
    while (wait3(&status, WNOHANG, (struct rusage *) 0) >= 0);
}
int main(int argc, char **argv) {
    SocketServer server;
    server.serverBindAndListen(HELLO_WORLD_SERVER_PORT);  // bind & listen

    //inform OS to run reaper as soon as it gets signal of child process exit...
    (void) signal(SIGCHLD, reaper);

    while (true) { //服务端是一直运行着一个死循环
        //accept返回一个新的socket fd, 代表着与客户端通信的连接, 也是一个文件
        int new_server_socket = server.serverAccept();
        int child_process_pid = fork();  //fork()后，子进程是主进程的拷贝
        if (child_process_pid == 0) {  // 子进程执行与客户端的交互，子进程专门用来和具体一个客户端进行通信
            serverWork(new_server_socket);
        }
        else if(child_process_pid>0) {//父进程
            close(new_server_socket);//父进程中不需要用于客户端交互的new_server_socket
        }
    }

    //关闭监听用的socket
    server.serverStopService();
    return 0;
}
