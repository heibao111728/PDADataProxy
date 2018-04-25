#pragma once
#ifndef __WIN32PDAWSDLL_H__
#define __WIN32PDAWSDLL_H__

#include "soapPdaWsSoapBindingProxy.h"

#ifdef _SOAPPDAWS
#define declspecAPI _declspec(dllexport) 
#else
#define declspecAPI _declspec(dllimport) 
#endif

class declspecAPI CPdaWs
{
public:
	CPdaWs();
	~CPdaWs();

	bool sendAlertMsg(std::string AlertMsg);
	void init(char* ip);

private:

	char m_endpoint[100];
	PdaWsSoapBindingProxy* m_pProxy;
	ns1__getPdaInfo *m_pns1__getPdaInfo_;
	ns1__getPdaInfoResponse m_ns1__getPdaInfoResponse_;
};

#endif // !__WIN32PDAWSDLL_H__

