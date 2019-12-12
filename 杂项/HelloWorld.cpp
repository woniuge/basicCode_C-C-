// HelloWorld.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MessageBox(NULL,TEXT("世界你好"),TEXT("问好"),MB_YESNO|MB_ICONQUESTION);
	return 0;
}



