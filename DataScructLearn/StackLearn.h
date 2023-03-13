#pragma once
#include <iostream>

class MyStack
{
public:
	MyStack(int size);
	//回收栈空间内存
	~MyStack();

	// 判断栈是否为空
	bool stackEmpty();
	// 判定栈是否已满
	bool stackFull();
	//清空栈
	void clearStack();
	int stackLength();

	bool push(int element);
	bool pop(int& element);
	bool getTopOfStack(int& element);
	void stackTraverse();
private:
	//栈空间指针
	int* m_pBuffer;
	// 栈容量
	int m_iSize;
	// 栈顶，也能代表栈中元素个数
	int m_iCurTop;
};


