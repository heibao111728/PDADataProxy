#pragma once
#ifndef __SOAPCLIENT_H__
#define __SOAPCLIENT_H__

#include "Win32pdaWsDll\include\Win32pdaWsDll.h"
#include "MsgRepository\include\MsgRepository.h"
#include <iostream>
#include <process.h>

using namespace std;

class CSoapClient
{
public:
	CSoapClient();
	~CSoapClient();

	void run();
	void stop();

	static void threadProc(void * pVoid);
	void setEndpointIP_W(wstring ip);
	void setEndpointIP(string ip);

	bool sendMsg(string Msg);
private:
	CPdaWs m_CPdas;

	HANDLE m_threadHandle;
};

#endif
