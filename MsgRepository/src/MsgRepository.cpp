//#include "stdafx.h"

#include "MsgRepository\include\MsgRepository.h"

CMsgRepository::CMsgRepository(int capacity)
{
	m_pfifo = new CMyFifo(capacity);
}

CMsgRepository::~CMsgRepository()
{
}

bool CMsgRepository::putMsg(string data)
{
	if (NULL != m_pfifo)
	{
		return m_pfifo->forcePush(data);
	}
	else
	{
		return false;
	}
}

string CMsgRepository::getMsg()
{
	if (NULL != m_pfifo)
	{
		CMyNode* pNode = m_pfifo->pop();
		if (NULL != pNode)
		{
			return pNode->getData();
		}
		else
		{
			return string("");
		}
	}
	else
	{
		return string("");
	}
}

void CMsgRepository::clean()
{
	if (NULL != m_pfifo)
	{
		m_pfifo->clean();
	}
}

bool CMsgRepository::setCapacity(int capacity)
{
	if (NULL != m_pfifo)
	{
		m_pfifo->setCapacity(capacity);
		return true;
	}
	else
	{
		return false;
	}
}

int CMsgRepository::getMsgCount()
{
	if (NULL != m_pfifo)
	{
		return m_pfifo->size();
	}
	else
	{
		return 0;
	}
}

int CMsgRepository::getCapacity()
{
	if (NULL != m_pfifo)
	{
		return m_pfifo->capacity();
	}
	else
	{
		return 0;
	}
}