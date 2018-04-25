
// PDADataProxyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PDADataProxy.h"
#include "PDADataProxyDlg.h"
#include "afxdialogex.h"

CMsgRepository* g_pMsgRepository;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define KEEPALIVE_TIMMER		(WM_USER+100)
#define UPDATASTATE_TIMMER		(WM_USER+101)

HWND g_hWnd;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPDADataProxyDlg dialog



CPDADataProxyDlg::CPDADataProxyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PDADATAPROXY_DIALOG, pParent)
	, m_strRcv(_T(""))
	, m_strSvrIp(_T("20.0.8.10"))
	, m_iSvrPort(61402)
	, m_strUserName(_T("User1"))
	, m_strPwd(_T(""))
	, m_MsgRepoCapacity(0)
	, m_MsgRepoCurSize(0)
	, m_javawebsvr_ip(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_iSwitch = 1;//初始状态为停止接收数据
}

void CPDADataProxyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCV, m_strRcv);
	DDX_Text(pDX, IDC_EDIT_SVR_IP, m_strSvrIp);
	DDX_Text(pDX, IDC_EDIT_SVR_PORT, m_iSvrPort);
	DDX_Text(pDX, IDC_EDIT_USER_NAME, m_strUserName);
	DDX_Text(pDX, IDC_EDIT_PWD, m_strPwd);
	DDX_Text(pDX, IDC_EDIT_REPO_CAPACITY, m_MsgRepoCapacity);
	DDX_Text(pDX, IDC_EDIT_REPO_CUR_SIZE, m_MsgRepoCurSize);
	DDX_Text(pDX, IDC_EDIT_JAVAWESVR_IP, m_javawebsvr_ip);
}

BEGIN_MESSAGE_MAP(CPDADataProxyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONN_TO_SVR, &CPDADataProxyDlg::OnBnClickedButtonConnToSvr)
	ON_MESSAGE(WM_USER_ONRECEIVE, &CPDADataProxyDlg::OnUserOnreceive)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_SWITCH, &CPDADataProxyDlg::OnBnClickedBtnSwitch)
END_MESSAGE_MAP()


// CPDADataProxyDlg message handlers

BOOL CPDADataProxyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	g_pMsgRepository = new CMsgRepository(100);
	m_soapClient = new CSoapClient();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPDADataProxyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPDADataProxyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPDADataProxyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPDADataProxyDlg::OnBnClickedButtonConnToSvr()
{
	// TODO: Add your control notification handler code here

	//初始化全局窗口句柄，方便其他模块往此窗口发消息
	UpdateData(true);
	g_hWnd = this->GetSafeHwnd();

	//char TmpBuf[10 * 1024] = { 0 }; //存放待发送的数据

#if 0
	char strIP[30] = { 0 };
	char strUser[30] = { 0 };
	char strPwd[30] = { 0 };

	int iLen = -1;

	//将ip地址由unicode转换为multicode
	iLen = ::WideCharToMultiByte(CP_ACP, 0, m_strSvrIp, -1, NULL, 0, NULL, NULL);
	::WideCharToMultiByte(CP_ACP, 0, m_strSvrIp, -1, strIP, iLen, NULL, NULL);

	//将user由unicode转换为multicode
	iLen = ::WideCharToMultiByte(CP_ACP, 0, m_strUserName, -1, NULL, 0, NULL, NULL);
	::WideCharToMultiByte(CP_ACP, 0, m_strUserName, -1, strUser, iLen, NULL, NULL);

	//将pwd由unicode转换为multicode
	iLen = ::WideCharToMultiByte(CP_ACP, 0, m_strPwd, -1, NULL, 0, NULL, NULL);
	::WideCharToMultiByte(CP_ACP, 0, m_strPwd, -1, strPwd, iLen, NULL, NULL);

#endif 
	m_phyteraClient = new CHyteraClient(
											m_strSvrIp.GetString(), 
											m_iSvrPort, 
											m_strUserName.GetString(), 
											m_strPwd.GetString());

	if (NULL != m_phyteraClient)
	{
		if (!m_phyteraClient->login())
		{
			//login failure
			return;
		}
	}

	SetTimer(KEEPALIVE_TIMMER, 10 * 1000, NULL);
	SetTimer(UPDATASTATE_TIMMER, 1 * 1000, NULL);
	return;
}

afx_msg LRESULT CPDADataProxyDlg::OnUserOnreceive(WPARAM wParam, LPARAM lParam)
{
	char* pMsg = (char*)(wParam);
	m_strRcv = pMsg;
	UpdateData(false);

	/*if (NULL != pMsg)
	{
		delete pMsg;
		pMsg = NULL;
	}*/
	return 0;
}

void CPDADataProxyDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	

	switch (nIDEvent)
	{
		case KEEPALIVE_TIMMER:
		{
			SendKeepAliveMsg();
			break;
		}

		case UPDATASTATE_TIMMER:
		{
			UpdataState();
			break;
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CPDADataProxyDlg::OnBnClickedBtnSwitch()
{
	// TODO: Add your control notification handler code here
	switch ( m_iSwitch )
	{
	case 1:
		{
			//sendStartRequest();
			start();
			m_iSwitch = 0;
			SetDlgItemText(IDC_BTN_SWITCH, _T("Stop"));
			break;
		}
	case 0:
		{
			//sendStopRequest();
			stop();
			m_iSwitch = 1;
			SetDlgItemText(IDC_BTN_SWITCH, _T("Start"));
			break;
		}
	default:
		break;
	}
}

void CPDADataProxyDlg::sendStartRequest()
{
	if (NULL != m_phyteraClient)
	{
		m_phyteraClient->StartMonitorAllGPS();
	}
}

void CPDADataProxyDlg::sendStopRequest()
{
	if (NULL != m_phyteraClient)
	{
		m_phyteraClient->StopMonitorAllGPS();
	}
}

int CPDADataProxyDlg::getMsgRepoSize()
{
	if (NULL != g_pMsgRepository)
	{
		return g_pMsgRepository->getMsgCount();
	}
	else
	{
		return 0;
	}
}

int CPDADataProxyDlg::getMsgRepoCapacity()
{
	if (NULL != g_pMsgRepository)
	{
		return g_pMsgRepository->getCapacity();
	}
	else
	{
		return 0;
	}
}

void CPDADataProxyDlg::SendKeepAliveMsg()
{
	if (NULL != m_phyteraClient)
	{
		m_phyteraClient->KeepAlive();
	}
}

void CPDADataProxyDlg::UpdataState()
{
	if (NULL != g_pMsgRepository)
	{
		m_MsgRepoCurSize = g_pMsgRepository->getMsgCount();
		m_MsgRepoCapacity = g_pMsgRepository->getCapacity();
	}

	UpdateData(FALSE);
}

void CPDADataProxyDlg::start()
{
	sendStartRequest();

	if (NULL != m_soapClient)
	{
		m_soapClient->setEndpointIP_W(m_javawebsvr_ip.GetString());
		m_soapClient->run();
	}
}

void CPDADataProxyDlg::stop()
{
	sendStopRequest();
}