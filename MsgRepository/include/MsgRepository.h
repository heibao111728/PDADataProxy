/**
*
*	description:	use fifo data struct to storage msg, if the counter of msg larger than
*					the capacity of fifo, delete msg on front of fifo then insert the new 
*					msg.  
*
*	date:			20170517
*	author:			dyang
*
*/

#pragma once

#ifndef __MSGREPOSITORY_H__
#define __MSGREPOSITORY_H__

#include "MyFifo.h"

class CMsgRepository
{
public:
	CMsgRepository(int capacity = 100);
	~CMsgRepository();

	bool putMsg(string data);
	string getMsg();

	void clean();
	bool setCapacity(int capacity);

	int getMsgCount();
	int getCapacity();

private:
	CMyFifo* m_pfifo;
};

#endif // !__MSGREPOSITORY_H__
