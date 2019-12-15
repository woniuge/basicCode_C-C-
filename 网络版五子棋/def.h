/*程序名：def.h
*功能：完成各控件、网络、状态的宏定义
*作者：袁海峰
*日期：2017年11月31日
*/


//棋盘定义
#define FRAME_WIDE 20
#define INTERVAL 40
#define NUMBER 15
//窗口定义
#define BACK_GROUND_COLOR 0xdcdcdc
#define PANEL (INTERVAL)+10
#define WINDOW_WIDE (FRAME_WIDE*2+INTERVAL*(NUMBER-1)+GetSystemMetrics(SM_CXFRAME)*2)
#define WINDOW_HIGH (FRAME_WIDE*2+INTERVAL*(NUMBER-1)+PANEL+GetSystemMetrics(SM_CYFRAME)*2+GetSystemMetrics(SM_CYCAPTION)+PANEL)
//控件ID定义
#define BN_CREATE_SERVER 1
#define BN_CONNECT_SERVER 2
#define BN_REPLAY 3

#define ET_PORT_SER 90
#define ET_IP 91
#define ET_PORT_CLI 92


//界面定义
#define INTERFACE_DISPOINT_X (FRAME_WIDE)
#define INTERFACE_DISPOINT_Y (FRAME_WIDE+INTERVAL*(NUMBER-1)+FRAME_WIDE)


//网络定义
#define WM_NETWORK_SER (WM_USER+0)
#define WM_NETWORK_CLI (WM_USER+1)

//状态定义
#define SERVER_CREATE_OVER 1
#define ACCEPT_CLIENT 2

#define CONNECT_OVER 11

#define SERVER_TIME 21
#define CLIENT_TIME 22

#define WAIT_FOR_OTHER 31
//游戏状态
#define SERVER 41
#define CLIENT 42

#define SERVER_PLAY SERVER
#define CLIENT_PLAY CLIENT

#define CONTINUE 60
#define BLACK_WIN 61
#define WHITE_WIN 62
//棋子
#define EMPTY 0
#define BLACK 1
#define WHITE 2
