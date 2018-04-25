#include "HyteraClient\include\HyteraClient.h"

CHyteraClient::CHyteraClient(wstring ip, int port, wstring username, wstring userpwd)
{
	m_svrIP = ip;
	m_userName = username;
	m_userPwd = userpwd;
	m_svrPort = port;

	string svrIp(ip.begin(), ip.end());
	string userName(username.begin(), username.end());  //wstring 转换为string
	string Pwd(userpwd.begin(), userpwd.end());  //wstring 转换为string

	m_pConn = new CConnection((char*)svrIp.c_str(), m_svrPort);
}

CHyteraClient::~CHyteraClient()
{
	if (NULL != m_pConn)
	{
		m_pConn->closeFromSvr();

		delete m_pConn;
		m_pConn = NULL;
	}
}

bool CHyteraClient::login()
{
	bool bRet = false;

	wstring strXml = L"\
				<Hytera>\
					<Attribute>\
							  <ProductName>DWS-RS</ProductName>\
							  <Version>30</Version>\
							  <CmdName>AVL Login</CmdName>\
							  <CmdGUID>12453825-235325</CmdGUID>\
					</Attribute>\
					<Payload>\
							  <LoginType>AVL Client</LoginType>\
							  <ConnectType>Command</ConnectType>\
							  <Username>" + m_userName + wstring(L"</Username>") +
					wstring(L"<Password>") + m_userPwd + wstring(L"</Password>") +
			wstring(L"</Payload>")+
	wstring(L"</Hytera>");

	if (NULL != m_pConn)
	{
		bRet = m_pConn->connectToSvr();
		if (!bRet)
		{
			// connect to svr failure
			return bRet;
		}
		else
		{
			bRet = m_pConn->SendData(strXml);
			if (bRet)
			{
				//socket is valid
				m_pConn->myStartThread();
			}
		}
	}

	return bRet;
}

void CHyteraClient::KeepAlive()
{
	wstring strXml = L"\
    <Hytera>\
    <Attribute>\
    <ProductName>DWS-RS</ProductName>\
    <Version>30</Version>\
    <CmdName>HeartBeat</CmdName>\
    <CmdGUID>CC53823E-6730-4E7F-9FCD-1B7532004E6F</CmdGUID>\
    </Attribute>\
    <Payload>\
    <DateTime>2013-09-25 15:15:15</DateTime> </Payload>\
    </Hytera>";

	if (NULL != m_pConn)
	{
		m_pConn->SendData(strXml);
	}
}

bool CHyteraClient::isConnected()
{
	if (NULL != m_pConn)
	{
		return m_pConn->isAlive();
	}
	else
	{
		return false;
	}
}

bool CHyteraClient::logout()
{
	return true;
}

int CHyteraClient::sendData(std::string data)
{
	return 1;
}

void CHyteraClient::StartMonitorAllGPS()
{
	wstring strXml = L"\
        <Hytera>\
        <Attribute>\
        <ProductName>DWS-RS</ProductName>\
        <Version>30</Version>\
        <CmdName>Start Monitor All GPS</CmdName>\
        <CmdGUID>12453825-212335325</CmdGUID>\
        </Attribute>\
        <Payload>\
        </Payload>\
        </Hytera>";

	if (NULL != m_pConn)
	{
		if (m_pConn->isAlive())
		{
			m_pConn->SendData(strXml);
		}
		else
		{
			//连接不存在
		}
	}
}

void CHyteraClient::StopMonitorAllGPS()
{
	wstring strXml = L"\
        <Hytera>\
        <Attribute>\
        <ProductName>DWS-RS</ProductName>\
        <Version>30</Version>\
        <CmdName>Stop Monitor All GPS</CmdName>\
        <CmdGUID>43535-fgdgdh</CmdGUID>\
        </Attribute>\
        <Payload>\
        </Payload>\
        </Hytera>";

	if (NULL != m_pConn)
	{
		m_pConn->SendData(strXml);
	}
}
