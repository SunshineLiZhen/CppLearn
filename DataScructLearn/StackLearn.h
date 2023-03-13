#pragma once
#include <iostream>

class MyStack
{
public:
	MyStack(int size);
	//����ջ�ռ��ڴ�
	~MyStack();

	// �ж�ջ�Ƿ�Ϊ��
	bool stackEmpty();
	// �ж�ջ�Ƿ�����
	bool stackFull();
	//���ջ
	void clearStack();
	int stackLength();

	bool push(int element);
	bool pop(int& element);
	bool getTopOfStack(int& element);
	void stackTraverse();
private:
	//ջ�ռ�ָ��
	int* m_pBuffer;
	// ջ����
	int m_iSize;
	// ջ����Ҳ�ܴ���ջ��Ԫ�ظ���
	int m_iCurTop;
};


