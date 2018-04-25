#ifndef __CONNECTION_H__
#define __CONNECTION_H__

#include "PDADataProxy\mygloble.h"
#include <Windows.h>
#include <process.h>
#include <iostream>

using namespace std;

#define MAX_RECEIVEBUFFERSIZE 100 * 1024

class CConnection
{
public:
#if 0
	static CConnection * GetInstance()
	{
		
		if(m_pConnectionInstance == NULL)  //判断是否第一次调用  
		{
			m_pConnectionInstance = new CConnection();
	        return m_pConnectionInstance; 
		}
	}
#endif
	CConnection(char* ip, int port);
	virtual ~CConnection();
	
	static CConnection* m_pConnectionInstance;

public:
	//connect to svr
	bool connectToSvr();
	void closeFromSvr();

	int SendData(wstring strData);
	int SendData(string strData);

	int RecvData();
	int RecvData(char* Buf, int len);
	int RecvData(wchar_t* wBuf, int len);

    int ReadHeader();

	int onReadAble();
	int onWritenable();
	void onError();
	
	void eventLoop();
	void singleStep();

	void myStartThread();
	void myStopThread();

    bool createLogFile();
    void closeLogFile();

	bool isAlive();

	static void threadProc( void * pVoid );

	//void MyPostMessage(HWND hWnd, UINT Msg, char* MsgContext);

private:
	char m_psvrIP[20];
	int m_svrPort;

	bool m_isConnected;

	char m_RecvBuf[MAX_RECEIVEBUFFERSIZE];
    wchar_t m_RecvBuf2[MAX_RECEIVEBUFFERSIZE];

	SOCKET	m_socket;
	SOCKADDR_IN m_ConnectAddr;

	HANDLE m_threadHandle;

	FILE* m_logger;
	char m_pRecvLogFileName[30];
};
#endif