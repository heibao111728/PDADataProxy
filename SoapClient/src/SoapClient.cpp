
#include "SoapClient\include\SoapClient.h"

extern CMsgRepository* g_pMsgRepository;

CSoapClient::CSoapClient()
{

}
CSoapClient::~CSoapClient()
{

}

bool CSoapClient::sendMsg(string Msg)
{
	return m_CPdas.sendAlertMsg(Msg);
}

void CSoapClient::run()
{
	//start send Msg
	m_threadHandle = (HANDLE)_beginthread(threadProc, 0, (void*)this);
}

void CSoapClient::stop()
{
	if (NULL == m_threadHandle)
	{
		CloseHandle(m_threadHandle);
	}
}

void CSoapClient::threadProc(void * pVoid)
{
	string tmpMsg;
	while (1)
	{
		if (NULL != pVoid && NULL != g_pMsgRepository)
		{
			tmpMsg = g_pMsgRepository->getMsg();
			if (!tmpMsg.empty())
			{
				((CSoapClient*)pVoid)->sendMsg(tmpMsg);
			}
		}
		Sleep(500);
	}
}

void CSoapClient::setEndpointIP_W(wstring ip)
{
	string endpiont_ip(ip.begin(), ip.end());
	m_CPdas.init((char*)endpiont_ip.c_str());
}

void CSoapClient::setEndpointIP(string ip)
{
}