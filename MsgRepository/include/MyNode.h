/**
*
*	description:	Node of fifo
*
*	date:			20170517
*	author:			dyang
*
*/

#pragma once

#ifndef __MYNODE_H__
#define __MYNODE_H__

#include <iostream>

class CMyNode
{
public:
	CMyNode();
	~CMyNode();

	void release();
	void setData(std::string data);
	std::string getData();

	//void showData();
private:
	std::string m_data;

public:
	CMyNode* next;
};

#endif