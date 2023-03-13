#pragma once
//#include "ClassSet.h"

#if 0
class DataStructLearn
{
public:
	DataStructLearn();
	~DataStructLearn();
};

class MyQueue
{
public:
	// ��������
	MyQueue(int queueCapacity);
	// ���ٶ���
	virtual ~MyQueue();
	// �пն���
	bool QueueEmpty() const;
	// ��������
	bool QueueFull() const;
	// ���г���
	int QueueLength() const;

	// ��ն���
	void ClearQueue();
	//��Ԫ�����
	bool EnQueue(int element);
	// ��Ԫ�س���
	bool DeQueue(int &element);
	// ��������
	void QueueTraverse();
private: 
	// ��������ָ��
	int* m_pQueue;
	// ����Ԫ�ظ���
	int m_iQueueLen;
	// ������������
	int m_iQueueCapacity;

	// ͷ������
	int m_iHead;
	// β������
	int m_iTail; 
};


/*****************************************************************************/
/* ջ
*/
class MyStack2
{
public:
	MyStack2(int size);
	//����ջ�ռ��ڴ�
	~MyStack2();

	// �ж�ջ�Ƿ�Ϊ��
	bool stackEmpty();
	// �ж�ջ�Ƿ�����
	bool stackFull();
	//���ջ
	void clearStack();
	int stackLength();

	bool push(Coordinate element);
	bool pop(Coordinate &element);
	bool getTopOfStack(Coordinate &element);
	void stackTraverse();
private:
	//ջ�ռ�ָ��
	Coordinate* m_pBuffer;
	// ջ����
	int m_iSize;
	// ջ����Ҳ�ܴ���ջ��Ԫ�ظ���
	int m_iTop;
};

/*****************************************************************************/
/*  ���Ա�--˳���
*/
/*****************************************************************************/
class MyList
{
public:
	MyList(int size);
	~MyList();

	// �ж����Ա��Ƿ��
	bool listEmpty();
	// �ж����Ǳ��Ƿ���
	bool listFull();
	// ������Ա���
	int listLength();

	void clearList();
	bool getElement(int pos,int &element);
	int locateElem(int element);
	bool priorElem(int currentElem, int &preElem);
	bool nextElem(int currentElem, int &nextElem);
	bool insertList(int pos,int element);
	bool deleteList(int pos,int &element);
	void listTraverse();
private:
	int* m_pBuffer;
	int m_iSize;
	int m_iLength;
};

/*****************************************************************************/
/*  ���Ա�--������
*/
/*****************************************************************************/
class Node
{
public:
	int data = 0;
	Node* next = nullptr;
	void printNode();
};

class MyLinkList
{
public:
	// ����������
	MyLinkList();
	~MyLinkList();

	//�鿴״̬
	bool listEmpty();
	int listLength();

	void clearList();
	int locateElem(Node* pNode);
	bool priorElem(Node* pCurrentNode, Node* pPreNode);
	bool nexdtElem(Node* pCurrentNode, Node* pNextNode);
	// ����ڵ�
	bool insertList(int i,Node* pNode);

	// ɾ���ڵ�
	bool deletteList(int i,Node* pNode);

	bool listInsertHead(Node* pNode);
	bool listInsertTail(Node* pNode);
	// ����
	void listInvert();
	// �������
	void listTraverse();
private:
	Node* m_pList;
	int m_iLength;
};

/*****************************************************************************/
/*  ����洢--��
*/
/*****************************************************************************/

// �ڵ�Ҫ�أ�����  ���� ���ڵ�  ��ڵ� �ҽڵ�
class TreeNode
{
public:
	int index;//����Ҳ������������˳��
	int data;
	TreeNode* pLChild;
	TreeNode* pRChild;
	TreeNode* pParent;
	TreeNode* searchNode(int nodeIndex);    
};

// ���������-��ȫ������  
class MyLinkTree
{
public:
	MyLinkTree(int n);
	~MyLinkTree();

	// �������ı���
	void preOrderTraverse() const;
	void inOrderTraverse() const;
	void postOrderTraverse() const;

	// �����������
	int treeDepth() const;

	TreeNode* searchNode(int nodeIndex);
	bool addNode(int nodeIndex, int direction, TreeNode* pNode);
	bool deleteNode(int nodeIndex, TreeNode* pNode);

private:
	TreeNode* creatFullTree(TreeNode* T, int* num, int& index);
	void preOrderTraverse(TreeNode* root) const;
	void inOrderTraverse(TreeNode* root) const;
	void postOrderTraverse(TreeNode* root) const;

	int treeDepth(TreeNode* node) const;
private:
	TreeNode* m_pRoot;
};

#endif