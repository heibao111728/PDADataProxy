/**
*
*	description:	my fifo data struct 
*
*	date:			20170517
*	author:			dyang
*
*/

#pragma once
#ifndef __MYFIFO_H__
#define __MYFIFO_H__
#include "MyNode.h"

using namespace std;

class CMyFifo
{
public:
	CMyFifo(int capacity = 100);
	~CMyFifo();

	CMyNode* pop();
	bool push(CMyNode* pnode);
	bool push(std::string data);
	bool forcePush(CMyNode* pnode);
	bool forcePush(std::string data);

	void clean();
	int size();// return m_size
	int capacity(); 
	void setCapacity(int capacity);

	bool IsEmpty();
	bool IsFull();

private:
	int m_size;//current size
	int m_capacity; // max size

	CMyNode* m_phead;
	CMyNode* m_ptail;

	bool m_isEmpty;
};

#endif // !__MYFIFO_H__

