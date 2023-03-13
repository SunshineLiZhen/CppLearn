#include "StackLearn.h"

using namespace std;

MyStack::MyStack(int size)
{
	m_pBuffer = new int[size];
	m_iSize = size;
	m_iTop = 0;
}

MyStack::~MyStack()
{
	delete[]m_pBuffer;
	m_pBuffer = nullptr;
}

bool MyStack::stackEmpty()
{
	if (0 == m_iTop)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyStack::stackFull()
{
	if (m_iTop == m_iSize)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void MyStack::clearStack()
{
	m_iTop = 0;
}

int MyStack::stackLength()
{
	return m_iTop;
}

bool MyStack::push(int element)
{
	if (stackFull())
	{
		return false;
	}
	else
	{
		m_pBuffer[m_iTop] = element;
		m_iTop++;
		return true;
	}
}

bool MyStack::pop(int& element)
{
	if (stackEmpty())
	{
		return false;
	}
	else
	{
		m_iTop--;
		element = m_pBuffer[m_iTop];
		return true;
	}
}

bool MyStack::getTopOfStack(int& element)
{
	if (stackEmpty())
	{
		return false;
	}
	else
	{
		element = m_pBuffer[m_iTop - 1];
	}
	return false;
}

void MyStack::stackTraverse()
{
	for (int i = 0; i < m_iTop; ++i)
	{
		cout << m_pBuffer[i] << endl;
	}
}
