//#include "stdafx.h"
#include "PUBLIC\include\connection\Connection.h"
#include "MsgRepository\include\MsgRepository.h"


extern HWND g_hWnd;
extern CMsgRepository* g_pMsgRepository;

CConnection::CConnection(char* ip, int port)
{
	memset(m_psvrIP,0x00,20);
	memset(m_RecvBuf,0x00,MAX_RECEIVEBUFFERSIZE);
    wmemset( m_RecvBuf2, 0x00, MAX_RECEIVEBUFFERSIZE );

	m_logger = NULL;
	memset(m_pRecvLogFileName,0x00,30);

	sprintf(m_psvrIP, "%s", ip);
	sprintf_s(m_pRecvLogFileName,"%s","AVLRecvData.txt");

	m_svrPort = port;
	m_socket = 0;
	m_isConnected = false;

	memset((void *)&m_ConnectAddr,0,sizeof(m_ConnectAddr)); 
}
	
CConnection::~CConnection()
{
	closeFromSvr();
	WSACleanup();
}
	
CConnection* CConnection::m_pConnectionInstance = NULL;

bool CConnection::connectToSvr()
{
	int error = 0;
	int i_val = 0;

	WORD wVersionRequested; 
	WSADATA wsaData; 
	int err = 0; 

	char* NoteMsg;

	wVersionRequested = MAKEWORD(2, 2); 
	err = WSAStartup(wVersionRequested, &wsaData); 

	if(0 == m_socket)
	{
		m_socket = socket(AF_INET, SOCK_STREAM, 0);
		if(m_socket == INVALID_SOCKET)
		{
			MyPostMessage(g_hWnd, WM_USER_ONRECEIVE, "create socket! error ");
			return FALSE;
		}
	}

	// 可重用
	error = setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&i_val, sizeof(i_val));
	if(error == SOCKET_ERROR)
	{
		MyPostMessage(g_hWnd, WM_USER_ONRECEIVE, "setsockopt failure !");
		return FALSE;
	}

    //设置接收缓冲区大小
    int nRecvBufLen = 32 * 1024; //设置为32K
    setsockopt( m_socket, SOL_SOCKET, SO_RCVBUF, ( const char* )&nRecvBufLen, sizeof( int ) );

	//连接
	m_ConnectAddr.sin_family = AF_INET;
	m_ConnectAddr.sin_port = htons(m_svrPort);
	m_ConnectAddr.sin_addr.s_addr = inet_addr(m_psvrIP);

	if(SOCKET_ERROR == connect(m_socket, (SOCKADDR*)&m_ConnectAddr, sizeof(m_ConnectAddr)) )
	{
		MyPostMessage(g_hWnd, WM_USER_ONRECEIVE, "connect to svr failure!");
		return false;
	}
	else
	{
		//AfxMessageBox(_T("connect to svr success!"));
	}

	m_isConnected = true;
	return true;
}

int CConnection::SendData(wstring strData)
{
#if 0
    //int len1 = strData.GetLength();
    int unicodeLen = ::MultiByteToWideChar( CP_ACP, 0, strData.GetBuffer(), -1, NULL, 0 );
    int leng = unicodeLen*2;

    wchar_t * pUnicode;
    pUnicode = new wchar_t[unicodeLen+1];
    wmemset( pUnicode, 0x00, unicodeLen+1 );

    char* pBuf = NULL;
    pBuf = new char[leng+5];
    memset(pBuf, 0x00, leng+5);

    ::MultiByteToWideChar( CP_ACP, 0, strData.GetBuffer(), -1, (LPWSTR)pUnicode, unicodeLen ); 

    memcpy(pBuf, &leng, 4);
	memcpy(pBuf+5, pUnicode, leng);

    int sendlen = leng + 5;
	int sendSize = send(m_socket, pBuf, sendlen, 0);
    if(SOCKET_ERROR == sendSize)
    {
    
        int iMyerrCode = WSAGetLastError();
        if(10004 == iMyerrCode)
        {
        }
        int a;
    }
#endif 

	if (!isAlive())
	{
		return 0;
	}

	char* NoteBuf;
    char pBuf[MAX_RECEIVEBUFFERSIZE] = {0};
	int leng = strData.length()*2+1;

	memcpy(pBuf,&leng, 4);
	//memcpy_s(pBuf, sizeof(pBuf), &leng, 4);

	memcpy(pBuf+5, strData.c_str(), strData.length()*2);
	//memcpy_s(pBuf + 5, sizeof(pBuf)-5, strData.c_str(), strData.length() * 2);

	int sendlen = strData.length()*2 + 5;

	int sendSize = send(m_socket, pBuf, sendlen, 0);
    if(SOCKET_ERROR == sendSize)
    {
        int iErr = WSAGetLastError();
		iErr = WSAGetLastError();
		switch (iErr)
		{
			case WSAEMSGSIZE:
			{
				break;
			}

			case WSAECONNRESET:
			{
				MyPostMessage(g_hWnd, WM_USER_ONRECEIVE, "*********svr reset the connection.");
				closeFromSvr();
				break;
			}
		}
    }

	return sendSize;
}

int CConnection::SendData(string strData)
{
	return 0;
}

void CConnection::eventLoop()
{
	while( m_isConnected )
	{
		singleStep();
		//Sleep(5000);
	}
}

void CConnection::singleStep()
{
	char* NoteBuf;
	UINT	uMilliseconds	=100;
	TIMEVAL	stTime;
	TIMEVAL	*pstTime = NULL;
	if ( INFINITE != uMilliseconds ) 
	{
		stTime.tv_sec = uMilliseconds/1000;
		stTime.tv_usec = 1000*(uMilliseconds%1000);
		pstTime = &stTime;
	}

	fd_set		readfd;
	fd_set		writefd;
	fd_set		errorfd;

	FD_ZERO(&readfd);
	FD_ZERO(&writefd);
	FD_ZERO(&errorfd);

	FD_SET(m_socket,&readfd);
	FD_SET(m_socket,&writefd);
	FD_SET(m_socket,&errorfd);

	int res = select(0, &readfd, &writefd, &errorfd, pstTime );
	if(res ==SOCKET_ERROR)
	{
		MyPostMessage(g_hWnd, WM_USER_ONRECEIVE, "socket error when execute select()!");
	}

	if(0 == res)
	{
		MyPostMessage(g_hWnd, WM_USER_ONRECEIVE, "timeout when execute select()!");
	}

	if( 0 < res )
	{
		if(FD_ISSET(m_socket,&readfd))
		{
			onReadAble();
		}
#if 0
		if(FD_ISSET(m_socket,&writefd))
		{
			onWritenable();
		}
#endif
		if(FD_ISSET(m_socket,&errorfd))
		{
			onError();
		}
	}
}

void CConnection::closeFromSvr()
{
	m_isConnected = false;

	if (m_socket != INVALID_SOCKET)
	{
		closesocket(m_socket);
		m_socket = INVALID_SOCKET;
	}
}

int CConnection::onReadAble()
{
	int readSize = -1;
    
	readSize = RecvData();
	return readSize;
}

int CConnection::onWritenable()
{
	int writeSize = -1;
	
	return writeSize;
}

void CConnection::onError()
{
	closeFromSvr();
}

int CConnection::RecvData()
{
	int iTmpRecvSize = 0;
	int iRecvSize = 0;

    int ireceivedLen = 0;
    int allLen = 0;
    char header[5+1] = {0};

	if (!isAlive())
	{
		return 0;
	}

	//获取数据包长度
	iRecvSize = recv(m_socket, (char*)header, 5, 0 );
	if (0 == iRecvSize)
	{
		closeFromSvr();
		return iRecvSize;
	}
	else if (0 < iRecvSize)
	{
		memcpy_s(&allLen, sizeof(int), header, 4);
		iRecvSize = 0;
	}

	while (allLen > ireceivedLen + 1)
	{
		iTmpRecvSize = recv(m_socket, ((char*)m_RecvBuf + ireceivedLen), MAX_RECEIVEBUFFERSIZE, 0);

		if (0 == iTmpRecvSize)
		{
			closeFromSvr();
			return iTmpRecvSize;
		}
		else if (0 < iTmpRecvSize)
		{
			ireceivedLen += iTmpRecvSize;
		}
	}

    wmemset( m_RecvBuf2, 0x00, MAX_RECEIVEBUFFERSIZE );
    memcpy(m_RecvBuf2, m_RecvBuf, MAX_RECEIVEBUFFERSIZE-5);

	//将接收到的数据由unicode编码改为ansi
	int iLen = ::WideCharToMultiByte(CP_ACP, 0, (LPCWCH)m_RecvBuf, -1, NULL, 0, NULL, NULL);
	char* pElementText = new char[iLen + 1];
	::WideCharToMultiByte(CP_ACP, 0, (LPCWCH)m_RecvBuf, -1, pElementText, iLen, NULL, NULL);

	//store into msgPrository
	if ( NULL!= g_pMsgRepository)
	{
		g_pMsgRepository->putMsg(pElementText);
	}

	//post Msg To Dialog
	//::PostMessage(g_hWnd, WM_USER_ONRECEIVE, (WPARAM)(pElementText), 0);
	MyPostMessage(g_hWnd, WM_USER_ONRECEIVE, pElementText);
	return ireceivedLen;
}

int CConnection::RecvData(char* Buf, int len)
{
	if (!isAlive())
	{
		return 0;
	}

	//ASSERT(Buf);
	int iRecvSize = 0;

	if (NULL == Buf)
	{
		return -1;
	}

	iRecvSize = recv(m_socket, Buf, MAX_RECEIVEBUFFERSIZE, 0);

	if (SOCKET_ERROR == iRecvSize)
	{
		//error
	}
	else if (0 == iRecvSize)
	{
		closeFromSvr();
		return iRecvSize;
	}
	else if (0 < iRecvSize)
	{
		return iRecvSize;
	}
}

int CConnection::RecvData(wchar_t* wBuf, int len)
{
	return 0;
}

void CConnection::threadProc( void * pVoid )
{
	if( NULL != pVoid)
	{
		((CConnection*)pVoid)->eventLoop();
	}
}

void CConnection::myStartThread()
{
	m_threadHandle = (HANDLE)_beginthread( threadProc, 0, (void*)this );
}

void CConnection::myStopThread()
{
	_endthread();
}

bool CConnection::createLogFile()
{
	m_logger = fopen(m_pRecvLogFileName, "w+");
	if( NULL == m_logger )
	{
		//AfxMessageBox(_T("创建接受日志文件失败!"));
		return false;
	}
    return true;
}

void CConnection::closeLogFile()
{
    if(NULL != m_logger)
    {
        fclose(m_logger);
    }
}

int CConnection::ReadHeader()
{
    char resposeHeader[11] = {0};
    int iLen = -1;

    if ( 0 < recv(m_socket, resposeHeader, 5, MSG_PEEK ))
	{
		iLen = recv(m_socket, resposeHeader, 5, 0 );
		if( SOCKET_ERROR == iLen )
		{
			closeFromSvr();
		}
    }

    return iLen;
}

bool CConnection::isAlive()
{
	return(m_isConnected && (INVALID_SOCKET != m_socket ? true : false));
}

//void CConnection::MyPostMessage(HWND hWnd, UINT Msg, char* MsgContext)
//{
//	char* MsgBuf = NULL;
//	MsgBuf = new char[strlen(MsgContext)];
//
//	if (NULL != MsgBuf)
//	{
//		memset(MsgBuf, 0x00, strlen(MsgContext));
//		sprintf(MsgBuf, "%s", MsgContext);
//		::PostMessage(hWnd, Msg, (WPARAM)(MsgBuf), 0);
//	}
//}
