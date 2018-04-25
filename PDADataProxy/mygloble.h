#ifndef __MYGLOBLE_H__
#define __MYGLOBLE_H__

#include <Windows.h>

#define WM_USER_ONRECEIVE (WM_USER+1)
#define WM_USER_ONMYPOSTMESSAGE (WM_USER+28)

void MyPostMessage(HWND hWnd, UINT Msg, char* MsgContext);

#endif 