#pragma once

#ifndef __HYTERACLIENT_H__
#define __HYTERACLIENT_H__

#include "PUBLIC\include\connection\Connection.h"
#include <process.h>
#include <Windows.h>
#include <string>

using namespace std;

class CHyteraClient
{
public:
	CHyteraClient(wstring ip, int port, wstring username, wstring userpwd);
	~CHyteraClient();

	bool login();
	bool logout();
	void KeepAlive();
	int sendData(std::string data);
	bool isConnected();

	void StartMonitorAllGPS();
	void StopMonitorAllGPS();

private:
	CConnection* m_pConn;

	wstring m_svrIP;
	wstring m_userName;
	wstring m_userPwd;
	int m_svrPort;
	bool m_isConnected;

	HANDLE m_hThreadHandle;
};

#endif