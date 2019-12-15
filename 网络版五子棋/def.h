/*��������def.h
*���ܣ���ɸ��ؼ������硢״̬�ĺ궨��
*���ߣ�Ԭ����
*���ڣ�2017��11��31��
*/


//���̶���
#define FRAME_WIDE 20
#define INTERVAL 40
#define NUMBER 15
//���ڶ���
#define BACK_GROUND_COLOR 0xdcdcdc
#define PANEL (INTERVAL)+10
#define WINDOW_WIDE (FRAME_WIDE*2+INTERVAL*(NUMBER-1)+GetSystemMetrics(SM_CXFRAME)*2)
#define WINDOW_HIGH (FRAME_WIDE*2+INTERVAL*(NUMBER-1)+PANEL+GetSystemMetrics(SM_CYFRAME)*2+GetSystemMetrics(SM_CYCAPTION)+PANEL)
//�ؼ�ID����
#define BN_CREATE_SERVER 1
#define BN_CONNECT_SERVER 2
#define BN_REPLAY 3

#define ET_PORT_SER 90
#define ET_IP 91
#define ET_PORT_CLI 92


//���涨��
#define INTERFACE_DISPOINT_X (FRAME_WIDE)
#define INTERFACE_DISPOINT_Y (FRAME_WIDE+INTERVAL*(NUMBER-1)+FRAME_WIDE)


//���綨��
#define WM_NETWORK_SER (WM_USER+0)
#define WM_NETWORK_CLI (WM_USER+1)

//״̬����
#define SERVER_CREATE_OVER 1
#define ACCEPT_CLIENT 2

#define CONNECT_OVER 11

#define SERVER_TIME 21
#define CLIENT_TIME 22

#define WAIT_FOR_OTHER 31
//��Ϸ״̬
#define SERVER 41
#define CLIENT 42

#define SERVER_PLAY SERVER
#define CLIENT_PLAY CLIENT

#define CONTINUE 60
#define BLACK_WIN 61
#define WHITE_WIN 62
//����
#define EMPTY 0
#define BLACK 1
#define WHITE 2
