//#include "stdafx.h"

#include "MsgRepository\include\MyFifo.h"

CMyFifo::CMyFifo(int capacity)
{
	m_size = 0;
	m_capacity = capacity;

	m_ptail = m_phead = NULL;

	m_isEmpty = true;
}

CMyFifo::~CMyFifo()
{
	clean();
}

CMyNode* CMyFifo::pop()
{
	CMyNode* pNode = NULL;
	if ( !IsEmpty() )
	{
		pNode = m_phead;
		m_phead = m_phead->next;
		m_size--;
	}

	if(IsEmpty())
	{
		m_phead = m_ptail = NULL;
	}
	return pNode;
}

bool CMyFifo::push(CMyNode* pnode)
{
	if ((NULL != pnode))
	{
		if (!IsFull())
		{
			if (NULL != m_ptail)
			{
				m_ptail->next = pnode;
				m_ptail = pnode;

				m_size++;
				return true;
			}
			else //first insert data
			{
				m_phead = m_ptail = pnode;
				m_size++;
				return true;
			}
		}
		else 
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool CMyFifo::push(std::string data)
{
	if (!IsFull())
	{
		CMyNode* pNode = new CMyNode();
		if (NULL != pNode)
		{
			pNode->setData(data);
			if (NULL != m_ptail)
			{
				m_ptail->next = pNode;
				m_ptail = pNode;

				m_size++;
				return true;
			}
			else //first insert data
			{
				m_phead = m_ptail = pNode;
				m_size++;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool CMyFifo::forcePush(CMyNode* pnode)
{
	CMyNode* pNode = NULL;
	if ( !IsFull() )
	{
		return push(pnode);
	}
	else //full
	{
		pNode = pop();
		if (NULL != pNode)
		{
			delete pNode;
			pNode = NULL;
		}
		return push(pnode);
	}
}

bool CMyFifo::forcePush(std::string data)
{
	CMyNode* pNode = NULL;
	if (!IsFull())
	{
		return push(data);
	}
	else //full
	{
		pNode = pop();
		if (NULL != pNode)
		{
			delete pNode;
			pNode = NULL;
		}
		return push(data);
	}
}

void CMyFifo::clean()
{
	CMyNode* pNode = NULL;
	while (!IsEmpty())
	{
		pNode = pop();
		if (NULL != pNode)
		{
			delete pNode;
			pNode = NULL;
		}
	}
	m_phead = m_ptail = NULL;
}

int CMyFifo::size()
{
	return m_size;
}

int CMyFifo::capacity()
{
	return m_capacity;
}

bool CMyFifo::IsEmpty()
{
	if (0 == m_size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CMyFifo::IsFull()
{
	if (m_capacity > 0 && m_size >= m_capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CMyFifo::setCapacity(int capacity)
{
	m_capacity = capacity;
}