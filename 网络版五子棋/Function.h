/*
		-------------------------
		-    作者:袁海峰        -
		-    时间:2017.11.31   -
		-    功能:网络版五子棋 -
		-------------------------
*/

//控件句柄
HWND SerPortEditHand;
HWND CreateServerButtonHand;
HWND IpEditHand;
HWND CliPortEditHand;
HWND ConnectButtonHand;
HWND ReplayButtonHand;

//服务器定义
WSADATA wsadata_ser;
SOCKET socket_ser_ser;
SOCKET socket_ser_cli;
SOCKADDR_IN sockaddr_ser_ser;
SOCKADDR_IN sockaddr_ser_cli;
int ser_cli_len = sizeof(sockaddr_ser_cli);
//客户端
WSADATA wsadata_cli;
SOCKET socket_cli_cli;
SOCKADDR_IN sockaddr_cli_ser;
//状态
int State = 0;
int GameState = NULL;
int Play = NULL;
int IsItPlaying = false;
int IfConnect = false;

char Ground[NUMBER][NUMBER] = {0};
void AbleInterface(HWND hwnd)
{
	if(!SetWindowLong(CreateServerButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
	{
		MessageBox(hwnd,"启用CreateServerButton按钮错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	if(!SetWindowLong(ConnectButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
	{
		MessageBox(hwnd,"启用ConnectButton按钮错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER | WS_DISABLED))
	{
		MessageBox(hwnd,"禁用ReplayButton按钮框错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
}

void RePlay(HWND hwnd)
{
	int x,y;
	State = 0;
	GameState = NULL;
	Play = NULL;
	IsItPlaying = false;
	for(x=0;x<NUMBER;x++)
	{
		for(y=0;y<NUMBER;y++)
		{
			Ground[x][y] = EMPTY;
		}
	}
	AbleInterface(hwnd);
	closesocket(socket_cli_cli);
	closesocket(socket_ser_cli);
	closesocket(socket_ser_ser);
	InvalidateRect(hwnd,NULL,TRUE);
	WSACleanup();
}

int PlayGame(int player,int x,int y);

void DrawPiece(HDC hdc)
{
	int x,y;
	for(x=0;x<NUMBER;x++)
	{
		for(y=0;y<NUMBER;y++)
		{
			if(Ground[x][y] == BLACK)
			{
				SelectObject(hdc,GetStockObject(BLACK_BRUSH));
				Ellipse(hdc,FRAME_WIDE+x*INTERVAL-16,FRAME_WIDE+y*INTERVAL-16,FRAME_WIDE+x*INTERVAL+16,FRAME_WIDE+y*INTERVAL+16);
			}
			if(Ground[x][y] == WHITE)
			{
				SelectObject(hdc,GetStockObject(WHITE_BRUSH));
				Ellipse(hdc,FRAME_WIDE+x*INTERVAL-16,FRAME_WIDE+y*INTERVAL-16,FRAME_WIDE+x*INTERVAL+16,FRAME_WIDE+y*INTERVAL+16);
			}
		}
	}
}

void DrawGroud(HWND hwnd,HDC hdc)
{
	int x,y;
	//纵向横线
	for(x=0;x<NUMBER;x++)
	{
		
		MoveToEx(hdc,FRAME_WIDE+x*INTERVAL,FRAME_WIDE,NULL);
		LineTo(hdc,FRAME_WIDE+x*INTERVAL,FRAME_WIDE+INTERVAL*(NUMBER-1));
	}
	//横向横线
	for(y=0;y<NUMBER;y++)
	{
		MoveToEx(hdc,FRAME_WIDE,FRAME_WIDE+y*INTERVAL,NULL);
		LineTo(hdc,FRAME_WIDE+INTERVAL*(NUMBER-1),FRAME_WIDE+y*INTERVAL);
	}//纵向数字
	SetBkColor(hdc,BACK_GROUND_COLOR);
	for(y=0;y<NUMBER;y++)
	{
		RECT text;
		text.right = FRAME_WIDE;
		text.left = text.right -20;
		text.top = FRAME_WIDE + y*INTERVAL - 8;
		text.bottom = text.top+15;
		char temp[3];
		itoa(y+1,temp,10);
		DrawText(hdc,temp,-1,&text,DT_CENTER);
	}//横向字母
	for(x=0;x<NUMBER;x++)
	{
		RECT text;
		text.bottom = FRAME_WIDE;
		text.top = text.bottom -20;
		text.left = FRAME_WIDE + x * INTERVAL -7;
		text.right = text.left+15;
		char temp[2]= " ";
		temp[0] = 65+x;
		DrawText(hdc,temp,-1,&text,DT_CENTER);
	}
	//界面文字
	RECT TextRect;
	TextRect.top = INTERFACE_DISPOINT_Y+7;
	TextRect.left = INTERFACE_DISPOINT_X;
	TextRect.bottom = TextRect.top+15;
	TextRect.right = TextRect.left+35;
	DrawText(hdc,TEXT("端口:"),-1,&TextRect,DT_RIGHT | DT_CENTER);
	TextRect.top = INTERFACE_DISPOINT_Y+7+30;
	TextRect.left = INTERFACE_DISPOINT_X;
	TextRect.bottom = TextRect.top+15;
	TextRect.right = TextRect.left+35;
	DrawText(hdc,TEXT("    IP:"),-1,&TextRect,DT_RIGHT | DT_CENTER);
	TextRect.top = INTERFACE_DISPOINT_Y+7+30;
	TextRect.left = INTERFACE_DISPOINT_X+35+115;
	TextRect.bottom = TextRect.top+15;
	TextRect.right = TextRect.left+35;
	DrawText(hdc,TEXT("端口:"),-1,&TextRect,DT_RIGHT | DT_CENTER);
	TextRect.top = INTERFACE_DISPOINT_Y+7+30+30;
	TextRect.left = INTERFACE_DISPOINT_X;
	TextRect.bottom = TextRect.top+15;
	TextRect.right = TextRect.left+800;
	switch(State)
	{
		//服务器端
	case SERVER_CREATE_OVER:
		DrawText(hdc,TEXT("服务器创建完毕!等待客户连接......"),-1,&TextRect,DT_LEFT);
		break;
	case ACCEPT_CLIENT:
		DrawText(hdc,TEXT("客户连接成功!游戏开始!您先手!"),-1,&TextRect,DT_LEFT);
		break;
	case SERVER_TIME:
		DrawText(hdc,TEXT("您的回合!"),-1,&TextRect,DT_LEFT);
		break;
	case BLACK_WIN:
		DrawText(hdc,TEXT("黑棋获得胜利!"),-1,&TextRect,DT_LEFT);
		break;
		//客户端
	case CONNECT_OVER:
		DrawText(hdc,TEXT("连接服务器成功!游戏开始!"),-1,&TextRect,DT_LEFT);
		break;
	case CLIENT_TIME:
		DrawText(hdc,TEXT("您的回合!"),-1,&TextRect,DT_LEFT);
		break;
	case WHITE_WIN:
		DrawText(hdc,TEXT("白棋获得胜利!"),-1,&TextRect,DT_LEFT);
		break;
		//公用
	case WAIT_FOR_OTHER:
		DrawText(hdc,TEXT("等待对方落子!"),-1,&TextRect,DT_LEFT);
		break;
	default:
		DrawText(hdc,TEXT("空闲!"),-1,&TextRect,DT_LEFT);
		break;
	}

	DrawPiece(hdc);
}

void DisableInterface(HWND hwnd)
{
	if(!SetWindowLong(CreateServerButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER | WS_DISABLED))
	{
		MessageBox(hwnd,"禁用CreateServerButton按钮错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	if(!SetWindowLong(ConnectButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER | WS_DISABLED))
	{
		MessageBox(hwnd,"禁用ConnectButton按钮错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
}

void CreatInterface(HWND ParentHwnd,HINSTANCE hInstance)
{
	SerPortEditHand = CreateWindow("EDIT","6666",WS_VISIBLE | WS_CHILD | ES_CENTER,INTERFACE_DISPOINT_X+35,INTERFACE_DISPOINT_Y+5,50,20,ParentHwnd,(HMENU)ET_PORT_SER,hInstance,NULL);
	CreateServerButtonHand = CreateWindow("BUTTON","创建服务器",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,INTERFACE_DISPOINT_X+35+55,INTERFACE_DISPOINT_Y,100,30,ParentHwnd,(HMENU)BN_CREATE_SERVER,hInstance,NULL);
	IpEditHand = CreateWindow("EDIT","000.000.000.000",WS_VISIBLE | WS_CHILD | ES_CENTER,INTERFACE_DISPOINT_X+35,INTERFACE_DISPOINT_Y+30+5,115,20,ParentHwnd,(HMENU)ET_IP,hInstance,NULL);
	CliPortEditHand = CreateWindow("EDIT","6666",WS_VISIBLE | WS_CHILD | ES_CENTER,INTERFACE_DISPOINT_X+35+115+35,INTERFACE_DISPOINT_Y+30+5,50,20,ParentHwnd,(HMENU)ET_PORT_CLI,hInstance,NULL);
	ConnectButtonHand = CreateWindow("BUTTON","连接服务器",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,INTERFACE_DISPOINT_X+35+115+35+55,INTERFACE_DISPOINT_Y+30,100,30,ParentHwnd,(HMENU)BN_CONNECT_SERVER,hInstance,NULL);
	ReplayButtonHand = CreateWindow("BUTTON","断开连接",WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON | WS_DISABLED,INTERFACE_DISPOINT_X+485,INTERFACE_DISPOINT_Y,75,60,ParentHwnd,(HMENU)BN_REPLAY,hInstance,NULL);
}

void CreateServer(HWND hwnd,int Port)
{
	if(WSAStartup(MAKEWORD(2,2),&wsadata_ser))
	{
		MessageBox(hwnd,"初始化服务器错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	socket_ser_ser = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sockaddr_ser_ser.sin_family = AF_INET;
	sockaddr_ser_ser.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	sockaddr_ser_ser.sin_port = htons(Port);
	if(bind(socket_ser_ser,(SOCKADDR*)&sockaddr_ser_ser,sizeof(SOCKADDR)))
	{
		MessageBox(hwnd,"绑定服务器错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	listen(socket_ser_ser,10);
	WSAAsyncSelect(socket_ser_ser,hwnd,WM_NETWORK_SER,FD_READ | FD_ACCEPT | FD_CLOSE | FD_CONNECT);
	DisableInterface(hwnd);
	State = SERVER_CREATE_OVER;
	InvalidateRect(hwnd,NULL,TRUE);
	Play = SERVER;
	GameState = SERVER_PLAY;

}

void ConnectServer(HWND hwnd,char adress_ip[13],int adress_port)
{
	if(WSAStartup(MAKEWORD(2,2),&wsadata_cli))
	{
		MessageBox(hwnd,"初始化客户端错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	socket_cli_cli = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	sockaddr_cli_ser.sin_family = AF_INET;
	sockaddr_cli_ser.sin_addr.S_un.S_addr = inet_addr(adress_ip);
	sockaddr_cli_ser.sin_port = htons(adress_port);
	if(connect(socket_cli_cli,(SOCKADDR*)&sockaddr_cli_ser,sizeof(SOCKADDR)))
	{
		MessageBox(hwnd,"无法连接服务器","错误",MB_OK | MB_ICONERROR);
		return;
	}
	WSAAsyncSelect(socket_cli_cli,hwnd,WM_NETWORK_CLI,FD_READ | FD_CLOSE | FD_CONNECT);
	DisableInterface(hwnd);
	if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
	{
		MessageBox(hwnd,"启用ReplayButton按钮框错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	State = CONNECT_OVER;
	InvalidateRect(hwnd,NULL,TRUE);
	Play = CLIENT;
	GameState = SERVER_PLAY;
	IsItPlaying =true;
}

void AcceptClient(HWND hwnd)
{
	socket_ser_cli = accept(socket_ser_ser,(SOCKADDR*)&socket_ser_cli,&ser_cli_len);
	IsItPlaying = true;
	State = ACCEPT_CLIENT;
	if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
	{
		MessageBox(hwnd,"启用ReplayButton按钮框错误","错误",MB_OK | MB_ICONERROR);
		return;
	}
	InvalidateRect(hwnd,NULL,TRUE);
}

void ServerRecv(HWND hwnd)
{
	POINT GamePos;
	char buf[257]=" ";
	recv(socket_ser_cli,buf,sizeof(buf),NULL);

	memcpy(&GamePos,buf,sizeof(POINT));
	switch(PlayGame(CLIENT,GamePos.x,GamePos.y))
	{
	case BLACK_WIN:
		State = BLACK_WIN;
		if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
		{
			MessageBox(hwnd,"启用Replay按钮框错误","错误",MB_OK | MB_ICONERROR);
			return;
		}
		InvalidateRect(hwnd,NULL,TRUE);
		return;
	case WHITE_WIN:
		State = WHITE_WIN;
		if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
		{
			MessageBox(hwnd,"启用Replay按钮框错误","错误",MB_OK | MB_ICONERROR);
			return;
		}
		InvalidateRect(hwnd,NULL,TRUE);
		return;
	case CONTINUE:
		break;
	}
	State = SERVER_TIME;
	InvalidateRect(hwnd,NULL,TRUE);
	GameState = SERVER_PLAY;
}

void ClientRecv(HWND hwnd)
{
	POINT GamePos;
	char buf[257]=" ";
	recv(socket_cli_cli,buf,sizeof(buf),NULL);

	memcpy(&GamePos,buf,sizeof(POINT));
	switch(PlayGame(SERVER,GamePos.x,GamePos.y))
	{
	case BLACK_WIN:
		State = BLACK_WIN;
		if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
		{
			MessageBox(hwnd,"启用Replay按钮框错误","错误",MB_OK | MB_ICONERROR);
			return;
		}
		InvalidateRect(hwnd,NULL,TRUE);
		return;
	case WHITE_WIN:
		State = WHITE_WIN;
		if(!SetWindowLong(ReplayButtonHand,GWL_STYLE,WS_VISIBLE | WS_CHILD | ES_CENTER))
		{
			MessageBox(hwnd,"启用Replay按钮框错误","错误",MB_OK | MB_ICONERROR);
			return;
		}
		InvalidateRect(hwnd,NULL,TRUE);
		return;
	case CONTINUE:
		break;
	}
	State = SERVER_TIME;
	InvalidateRect(hwnd,NULL,TRUE);
	GameState = CLIENT_PLAY;
}

int PlayGame(int player,int x,int y)
{
	if(player == SERVER)
	{
		Ground[x][y] = BLACK;
	}
	else if(player == CLIENT)
	{
		Ground[x][y] = WHITE;
	}
	int cout;
	int i;
	if(player == SERVER)
	{
		//横向
		cout=1;
		i=1;
		while(Ground[x-i][y] == BLACK)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x+i][y] == BLACK)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return BLACK_WIN;
		}
		//纵向
		cout=1;
		i=1;
		while(Ground[x][y-i] == BLACK)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x][y+i] == BLACK)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return BLACK_WIN;
		}
		//北偏东
		cout=1;
		i=1;
		while(Ground[x-i][y-i] == BLACK)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x+i][y+i] == BLACK)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return BLACK_WIN;
		}
		//北偏西
		cout=1;
		i=1;
		while(Ground[x-i][y+i] == BLACK)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x][y+i] == BLACK)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return BLACK_WIN;
		}
	}
	else if(player == CLIENT)
	{
		//横向
		cout=1;
		i=1;
		while(Ground[x-i][y] == WHITE)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x+i][y] == WHITE)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return WHITE_WIN;
		}
		//纵向
		cout=1;
		i=1;
		while(Ground[x][y-i] == WHITE)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x][y+i] == WHITE)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return WHITE_WIN;
		}
		//北偏东
		cout=1;
		i=1;
		while(Ground[x-i][y-i] == WHITE)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x+i][y+i] == WHITE)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return WHITE_WIN;
		}
		//北偏西
		cout=1;
		i=1;
		while(Ground[x-i][y+i] == WHITE)
		{
			cout++;
			i++;
		}
		i=1;
		while(Ground[x][y+i] == WHITE)
		{
			cout++;
			i++;
		}
		if(cout>=5)
		{
			IsItPlaying = false;
			return WHITE_WIN;
		}
	}
	return CONTINUE;
}

POINT GetGamePos(POINT MousePos)
{
	POINT GamePos;
	MousePos.x = MousePos.x-FRAME_WIDE;
	MousePos.y = MousePos.y-FRAME_WIDE;
	GamePos.x = MousePos.x/INTERVAL;
	GamePos.y = MousePos.y/INTERVAL;
	return GamePos;
}
