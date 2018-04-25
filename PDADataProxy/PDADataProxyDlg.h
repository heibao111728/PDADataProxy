
// PDADataProxyDlg.h : header file
//

#pragma once

//#include "Connection.h"
#include "HyteraClient\include\HyteraClient.h"
#include "MsgRepository\include\MsgRepository.h"
#include "SoapClient\include\SoapClient.h"

// CPDADataProxyDlg dialog
class CPDADataProxyDlg : public CDialogEx
{
// Construction
public:
	CPDADataProxyDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PDADATAPROXY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
public:
	CHyteraClient* m_phyteraClient;
	CSoapClient* m_soapClient;

protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnSwitch();
	afx_msg void OnBnClickedButtonConnToSvr();
	afx_msg LRESULT OnUserOnreceive(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	
	CString m_strRcv;
	CString m_strSvrIp;
	int m_iSvrPort;
	CString m_strUserName;
	CString m_strPwd;

	CString m_javawebsvr_ip;

	int m_iSwitch ;// 0:正在接收数据；1:停止接收数据

	int m_MsgRepoCapacity;
	int m_MsgRepoCurSize;

public:

	void sendStartRequest();
	void sendStopRequest();

	int getMsgRepoSize();
	int getMsgRepoCapacity();

	void SendKeepAliveMsg();
	void UpdataState();

	void start();
	void stop();
	
};
