//#include "stdafx.h"

#include "MsgRepository\include\MyNode.h"

CMyNode::CMyNode()
{
}

CMyNode::~CMyNode()
{
}

void CMyNode::release()
{
	if (NULL != this)
	{
		delete this;
	}
}

void CMyNode::setData(std::string data)
{
	m_data = data;
}

std::string CMyNode::getData()
{
	return m_data;
}