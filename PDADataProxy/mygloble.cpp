#include "mygloble.h"
#include "stdio.h"

void MyPostMessage(HWND hWnd, UINT Msg, char* MsgContext)
{
	char* MsgBuf = NULL;
	MsgBuf = new char[strlen(MsgContext)];

	if (NULL != MsgBuf)
	{
		memset(MsgBuf, 0x00, strlen(MsgContext));
		sprintf(MsgBuf, "%s", MsgContext);
		::PostMessage(hWnd, Msg, (WPARAM)(MsgBuf), 0);
	}
}