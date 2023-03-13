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
	// 创建队列
	MyQueue(int queueCapacity);
	// 销毁队列
	virtual ~MyQueue();
	// 判空队列
	bool QueueEmpty() const;
	// 判满队列
	bool QueueFull() const;
	// 队列长度
	int QueueLength() const;

	// 清空队列
	void ClearQueue();
	//新元素入队
	bool EnQueue(int element);
	// 首元素出队
	bool DeQueue(int &element);
	// 遍历队列
	void QueueTraverse();
private: 
	// 队列数组指针
	int* m_pQueue;
	// 队列元素个数
	int m_iQueueLen;
	// 队列数组容量
	int m_iQueueCapacity;

	// 头部索引
	int m_iHead;
	// 尾部索引
	int m_iTail; 
};


/*****************************************************************************/
/* 栈
*/
class MyStack2
{
public:
	MyStack2(int size);
	//回收栈空间内存
	~MyStack2();

	// 判断栈是否为空
	bool stackEmpty();
	// 判定栈是否已满
	bool stackFull();
	//清空栈
	void clearStack();
	int stackLength();

	bool push(Coordinate element);
	bool pop(Coordinate &element);
	bool getTopOfStack(Coordinate &element);
	void stackTraverse();
private:
	//栈空间指针
	Coordinate* m_pBuffer;
	// 栈容量
	int m_iSize;
	// 栈顶，也能代表栈中元素个数
	int m_iTop;
};

/*****************************************************************************/
/*  线性表--顺序表
*/
/*****************************************************************************/
class MyList
{
public:
	MyList(int size);
	~MyList();

	// 判断线性表是否空
	bool listEmpty();
	// 判断型星表是否满
	bool listFull();
	// 获得线性表长度
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
/*  线性表--单链表
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
	// 构造与析构
	MyLinkList();
	~MyLinkList();

	//查看状态
	bool listEmpty();
	int listLength();

	void clearList();
	int locateElem(Node* pNode);
	bool priorElem(Node* pCurrentNode, Node* pPreNode);
	bool nexdtElem(Node* pCurrentNode, Node* pNextNode);
	// 插入节点
	bool insertList(int i,Node* pNode);

	// 删除节点
	bool deletteList(int i,Node* pNode);

	bool listInsertHead(Node* pNode);
	bool listInsertTail(Node* pNode);
	// 反序
	void listInvert();
	// 链表遍历
	void listTraverse();
private:
	Node* m_pList;
	int m_iLength;
};

/*****************************************************************************/
/*  数组存储--树
*/
/*****************************************************************************/

// 节点要素：索引  数据 父节点  左节点 右节点
class TreeNode
{
public:
	int index;//索引也代表有序树的顺序
	int data;
	TreeNode* pLChild;
	TreeNode* pRChild;
	TreeNode* pParent;
	TreeNode* searchNode(int nodeIndex);    
};

// 链表二叉树-完全二叉树  
class MyLinkTree
{
public:
	MyLinkTree(int n);
	~MyLinkTree();

	// 二叉树的遍历
	void preOrderTraverse() const;
	void inOrderTraverse() const;
	void postOrderTraverse() const;

	// 二叉树的深度
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