#include "stdafx.h"
#include "Public/include/myLock.h"

CMyLock::CMyLock() 
{ 
	m_pCs = new CriticalSection(); 
}

CMyLock::~CMyLock() 
{ 
	if (NULL != m_pCs)
	{
		delete m_pCs;
		m_pCs = NULL;
	}
}

void CMyLock::lock() 
{ 
	if (NULL != m_pCs)
	{
		m_pCs->enterCriticalSection();
	}
}

void CMyLock::unlock() 
{
	if (NULL != m_pCs)
	{
		m_pCs->leaveCriticalSection();
	}
}