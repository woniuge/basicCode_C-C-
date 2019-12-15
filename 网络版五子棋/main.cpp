/*
	-------------------------
		-    作者:袁海峰        -
		-    时间:2017.11.31   -
		-    功能:网络版五子棋 -
		-------------------------
*/

#pragma comment (lib,"ws2_32.lib")
#include <iostream>
#include <string>
#include <WINSOCK2.H>
#include <windows.h>
#include "def.h"
#include "Function.h"

HINSTANCE HInstance;

long CALLBACK MainWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )
{
	HInstance = hInstance;
	WNDCLASS MainWnd;
	MainWnd.hInstance = hInstance;
	MainWnd.lpszClassName = "MW";
	MainWnd.lpfnWndProc = MainWndProc;
	MainWnd.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(0xdc,0xdc,0xdc));
	MainWnd.style = NULL;
	MainWnd.cbWndExtra = NULL;
	MainWnd.cbClsExtra = NULL;
	MainWnd.hCursor = LoadCursor(NULL,IDC_ARROW);
	MainWnd.lpszMenuName = NULL;
	MainWnd.hIcon = LoadIcon(NULL,IDI_ERROR);
	if(!RegisterClass(&MainWnd))
	{
		MessageBox(NULL,"创建窗口失败","提示",MB_OK);
		return -1;
	}
	HWND hwnd = CreateWindow("MW","五子棋网络版",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,WINDOW_WIDE,WINDOW_HIGH,NULL,NULL,hInstance,NULL);

	ShowWindow(hwnd,SW_SHOW);
	UpdateWindow(hwnd);
	MSG msg;
	while(GetMessage(&msg,NULL,NULL,NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

long CALLBACK MainWndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	POINT MousePos,GamePos;
	RECT WindowRect;
	char SendText[256];
	char SerPortText[] = "123456";
	int SerPort = atoi(SerPortText);
	char CliPortText[] = "123456",IpText[] = "000.000.000.000";
	int CliPort = atoi(CliPortText);
	switch(message)
	{
	case WM_LBUTTONUP:
		if(IsItPlaying == false)
					break;
		if(GameState == Play)
		{
			if(Play ==SERVER)
			{
				GetCursorPos(&MousePos);
				GetWindowRect(hwnd,&WindowRect);
				MousePos.x = MousePos.x -WindowRect.left;
				MousePos.y = MousePos.y -WindowRect.top;
				if(MousePos.x > FRAME_WIDE*2+INTERVAL*(NUMBER-1)+GetSystemMetrics(SM_CYCAPTION))
					break;
				if(MousePos.y > FRAME_WIDE*2+INTERVAL*(NUMBER-1)+GetSystemMetrics(SM_CYCAPTION))
					break;
				GamePos = GetGamePos(MousePos);
				if(Ground[GamePos.x][GamePos.y] != EMPTY)
					break;
				memcpy(SendText,&GamePos,sizeof(POINT));
				send(socket_ser_cli,SendText,sizeof(SendText),NULL);
				switch(PlayGame(SERVER,GamePos.x,GamePos.y))
				{
				case BLACK_WIN:
					State = BLACK_WIN;
					InvalidateRect(hwnd,NULL,TRUE);
					if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
					{
						MessageBox(hwnd,"启用Replay按钮错误","错误",MB_OK | MB_ICONERROR);
						return 0;
					}
					return 0;
				case WHITE_WIN:
					State = WHITE_WIN;
					InvalidateRect(hwnd,NULL,TRUE);
					if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
					{
						MessageBox(hwnd,"启用Replay按钮错误","错误",MB_OK | MB_ICONERROR);
						return 0;
					}
					return 0;
				case CONTINUE:
					break;
				}
				GameState = CLIENT_PLAY;
				State = WAIT_FOR_OTHER;
				InvalidateRect(hwnd,NULL,TRUE);
			}
			else if(Play == CLIENT)
			{
				GetCursorPos(&MousePos);
				GetWindowRect(hwnd,&WindowRect);
				MousePos.x = MousePos.x -WindowRect.left;
				MousePos.y = MousePos.y -WindowRect.top;
				if(MousePos.x > FRAME_WIDE*2+INTERVAL*(NUMBER-1)+GetSystemMetrics(SM_CYCAPTION))
					break;
				if(MousePos.y > FRAME_WIDE*2+INTERVAL*(NUMBER-1)+GetSystemMetrics(SM_CYCAPTION))
					break;
				GamePos = GetGamePos(MousePos);
				if(Ground[GamePos.x][GamePos.y] != EMPTY)
					break;
				memcpy(SendText,&GamePos,sizeof(POINT));
				send(socket_cli_cli,SendText,sizeof(SendText),NULL);
				switch(PlayGame(CLIENT,GamePos.x,GamePos.y))
				{
				case BLACK_WIN:
					State = BLACK_WIN;
					InvalidateRect(hwnd,NULL,TRUE);
					if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
					{
						MessageBox(hwnd,"启用Replay按钮错误","错误",MB_OK | MB_ICONERROR);
						return 0;
					}
					return 0;
				case WHITE_WIN:
					State = WHITE_WIN;
					InvalidateRect(hwnd,NULL,TRUE);
					if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
					{
						MessageBox(hwnd,"启用Replay按钮错误","错误",MB_OK | MB_ICONERROR);
						return 0;
					}
					return 0;
				case CONTINUE:
					break;
				}
				GameState = SERVER_PLAY;
				State = WAIT_FOR_OTHER;
				InvalidateRect(hwnd,NULL,TRUE);
			}
		}
		else
		{
			MessageBox(hwnd,"这还不是您的回合","提示",MB_OK);
		}
		break;
	case WM_CREATE:
		CreatInterface(hwnd,HInstance);
		break;
		//重绘
	case WM_PAINT:
		PAINTSTRUCT ps;
		hdc = BeginPaint(hwnd,&ps);
		DrawGroud(hwnd,hdc);
		EndPaint(hwnd,&ps);
		break;
		//控件处理
	case WM_COMMAND:
		switch(HIWORD(wParam))//判断通知吗
		{
		case BN_CLICKED:
			switch(LOWORD(wParam))//判断控件ID
			{
			case BN_CREATE_SERVER:
				GetWindowText(SerPortEditHand,SerPortText,sizeof(SerPortText));
				CreateServer(hwnd,SerPort);
				break;
			case BN_CONNECT_SERVER:
				GetWindowText(CliPortEditHand,CliPortText,sizeof(CliPortText));
				GetWindowText(IpEditHand,IpText,sizeof(IpText));
				ConnectServer(hwnd,IpText,CliPort);
				break;
			case BN_REPLAY:
				RePlay(hwnd);
				break;
			}
			break;
		}
		break;
		//服务器消息
	case WM_NETWORK_SER:
		switch(WSAGETASYNCBUFLEN(lParam))
		{
		case FD_ACCEPT:
			AcceptClient(hwnd);
			break;
		case FD_READ:
			ServerRecv(hwnd);
			break;
		case FD_CLOSE:
			RePlay(hwnd);
			break;
		}
		break;
		//客户端消息
	case WM_NETWORK_CLI:
		switch(WSAGETASYNCBUFLEN(lParam))
		{
		case FD_READ:
			ClientRecv(hwnd);
			break;
		case FD_CLOSE:
			RePlay(hwnd);
			break;
		}
		break;
		//关闭
	case WM_CLOSE:
		PostMessage(hwnd,WM_QUIT,NULL,NULL);
		break;
	case WM_QUIT:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd,message,wParam,lParam);
	}
	return 0;
}

