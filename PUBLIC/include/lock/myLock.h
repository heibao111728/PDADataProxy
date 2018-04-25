#pragma once

/**
*	description:	use CriticalSection Encapsulate to CMyLock.
*
*	date:			20170520
*
*	author:			dyang
*/

#ifndef __MYLOCK_H__
#define __MYLOCK_H__

#include <Windows.h>

class CriticalSection
{
public:
	CriticalSection() { InitializeCriticalSection(&criticalS); }
	~CriticalSection() { DeleteCriticalSection(&criticalS); }
	void enterCriticalSection() { EnterCriticalSection(&criticalS); }
	void leaveCriticalSection() { LeaveCriticalSection(&criticalS); }
private:
	CRITICAL_SECTION criticalS;
};

class CMyLock
{
public:
	CMyLock();
	~CMyLock();
	void lock();
	void unlock();

private:
	CriticalSection* m_pCs;
};

#endif // !__MYLOCK_H__
