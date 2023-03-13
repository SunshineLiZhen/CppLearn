#include "DataStruct.h"
#include <iostream>
using namespace std;

#if 0
DataStructLearn::DataStructLearn()
{
}


DataStructLearn::~DataStructLearn()
{
}

MyQueue::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	m_pQueue = new int[m_iQueueCapacity];
}

MyQueue::~MyQueue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
}

bool MyQueue::QueueEmpty() const
{
	if (0 == m_iQueueLen)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyQueue::QueueFull() const
{
	if (m_iQueueLen == m_iQueueCapacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int MyQueue::QueueLength() const
{
	return m_iQueueLen;
}

void MyQueue::ClearQueue()
{
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
}

bool MyQueue::EnQueue(int element)
{
	if (QueueFull())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail % m_iQueueCapacity;
		m_iQueueLen++;
	}
	return true;
}

bool MyQueue::DeQueue(int & element)
{
	if (QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_pQueue[m_iHead] = 0;//清空
		m_iHead++;
		m_iHead = m_iHead % m_iQueueCapacity;
		m_iQueueLen--;
	}
	return true;
}

void MyQueue::QueueTraverse()
{
	int k = m_iHead;
	for (int i = 0; i < m_iQueueLen; ++i)
	{
		cout << m_pQueue[k%m_iQueueCapacity] << endl;
		k++;
	}
}


////////////////////////////////////////
MyStack2::MyStack2(int size)
{
	m_pBuffer = new Coordinate[size];
	m_iSize = size;
	m_iTop = 0;
}

MyStack2::~MyStack2()
{
	delete[]m_pBuffer;
	m_pBuffer = NULL;
}

bool MyStack2::stackEmpty()
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

bool MyStack2::stackFull()
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

void MyStack2::clearStack()
{
	m_iTop = 0;
}

int MyStack2::stackLength()
{
	return m_iTop;
}

bool MyStack2::push(Coordinate element)
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

bool MyStack2::pop(Coordinate & element)
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

bool MyStack2::getTopOfStack(Coordinate & element)
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

void MyStack2::stackTraverse()
{
	for (int i = 0; i < m_iTop; ++i)
	{
		m_pBuffer[i].printInfo();
	}
}

MyList::MyList(int size)
{
	m_pBuffer = new int[size];
	m_iSize = size;
	m_iLength = 0;
}

MyList::~MyList()
{
	delete []m_pBuffer;
	m_pBuffer = NULL;
}

bool MyList::listEmpty()
{
	if (0 == m_iLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool MyList::listFull()
{
	if (0 == m_iLength)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int MyList::listLength()
{
	return m_iLength;
}

void MyList::clearList()
{
	m_iLength = 0;
}

bool MyList::getElement(int pos,int & element)
{
	if (pos < 0 || pos >= m_iLength)
	{
		return false;
	}
	
	element = m_pBuffer[pos];
	return true;
}

int MyList::locateElem(int element)
{
	for (int i = 0; i < m_iLength; ++i)
	{
		if (element == m_pBuffer[i])
		{
			return i;
		}
	}
	return -1;
}

bool MyList::priorElem(int currentElem, int & preElem)
{
	int pos = -1;
	pos = locateElem(pos);
	if (-1 == pos)
	{
		return false;
	}
	else
	{
		if (0 == pos)
		{
			return false;
		}
		else
		{
			preElem = m_pBuffer[pos - 1];
			return true;
		}
	}
}

bool MyList::nextElem(int currentElem, int & nextElem)
{
	int pos = -1;
	pos = locateElem(pos);
	if (-1 == pos)
	{
		return false;
	}
	else
	{
		if ((m_iLength-1) == pos)
		{
			return false;
		}
		else
		{
			nextElem = m_pBuffer[pos + 1];
			return true;
		}
	}
}

bool MyList::insertList(int pos, int element)
{
	if (listFull())
	{
		return false;
	}

	if (pos < 0 || pos > m_iLength)
	{
		return false;
	}
	
	//移动元素
	// 当pos == m_iLength时候，不走此循环，也不必移动元素
	for (int i = m_iLength - 1; i >= pos; --i)
	{
		m_pBuffer[i + 1] = m_pBuffer[i];
	}

	m_pBuffer[pos] = element;
	m_iLength++;

	return true;
}

bool MyList::deleteList(int pos,int &element)
{
	if (listEmpty())
	{
		return false;
	}

	//和插入时候不同pos不能等于m_iLength
	if (pos < 0 || pos >= m_iLength)
	{
		return false;
	}

	element = m_pBuffer[pos];
	for(int i = pos+1;i<m_iLength;++i)
	{
		m_pBuffer[i-1] = m_pBuffer[i];
	}

	m_iLength--;

	return true;
}

void MyList::listTraverse()
{
	for (int i = 0; i < m_iLength; ++i)
	{
		cout << m_pBuffer[i] << endl;
	}
}

///////////////////////////////////////////////////////////////////////////
void Node::printNode()
{
	cout << data << endl;
}

MyLinkList::MyLinkList()
{
	m_pList = new Node();
	m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;//头节点不放在列表当中
}

MyLinkList::~MyLinkList()
{
	clearList();
	delete m_pList;
	m_pList = NULL;
}

bool MyLinkList::listEmpty()
{
	if (0 == m_iLength)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int MyLinkList::listLength()
{
	return m_iLength;
}

void MyLinkList::clearList()
{
	Node* currentNode = m_pList->next;
	while (NULL != currentNode)
	{
		Node* tmp = currentNode->next;
		delete currentNode;
		currentNode = tmp;
	}

	m_iLength = 0;
	m_pList->next = NULL;
}

int MyLinkList::locateElem(Node * pNode)
{
	return 0;
}

bool MyLinkList::priorElem(Node * pCurrentNode, Node * pPreNode)
{
	return false;
}

bool MyLinkList::nexdtElem(Node * pCurrentNode, Node * pNextNode)
{
	return false;
}

bool MyLinkList::insertList(int i, Node * pNode)
{
	if (NULL == pNode)
	{
		return false;
	}

	if (i > m_iLength || i < 0)
	{
		return false;
	}

	int k = 0;
	Node* currentNode = m_pList;
	while (NULL != currentNode)
	{

		if (i == k)
		{
			break;
		}
		currentNode = currentNode->next;
		k++;
	}

	Node *newNode = new Node;
	if (NULL == newNode)
	{
		return false;
	}

	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;

	m_iLength++;

	return true;
}

bool MyLinkList::deletteList(int i, Node * pNode)
{
	if (NULL == pNode)
	{
		return false;
	}

	// 尾节点不能删除,头节点不能删除
	if (i <= 0 || i >= m_iLength)
	{
		return false;
	}

	int k = 1;
	Node* preNode = m_pList;
	Node* currentNode = m_pList->next;
	while (NULL != currentNode)
	{
		if (k == i)
		{
			break;
		}
		preNode = currentNode;
		currentNode = currentNode->next;
	}

	preNode->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;

	return false;
}

bool MyLinkList::listInsertHead(Node * pNode)
{
	if (NULL == pNode)
	{
		return false;
	}

	Node *newNode = new Node;
	if (NULL == newNode)
	{
		return false;
	}

	newNode->data = pNode->data;
	newNode->next = m_pList->next;
	m_pList->next = newNode;

	m_iLength++;

	return true;
}

bool MyLinkList::listInsertTail(Node * pNode)
{
	if (NULL == pNode)
	{
		return false;
	}
	Node* currentNode = m_pList;
	while (NULL != currentNode->next)
	{
		currentNode = currentNode->next;
	}
	Node *newNode = new Node;
	if (NULL == newNode)
	{
		return false;
	}
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;

	m_iLength++;

	return false;
}

void MyLinkList::listInvert()
{
	if (0 == m_iLength || 1 == m_iLength)
	{
		return;
	}

	// 头节点不变
	Node* preNode = m_pList->next;
	Node* currentNode = preNode->next;
	preNode->next = NULL;

	while (NULL != currentNode)
	{
		//操作
		Node* tmp = currentNode->next;
		currentNode->next = preNode;
		
		//更新循环变量
		preNode = currentNode;
		currentNode = tmp;
	}

	m_pList->next = preNode;
}

void MyLinkList::listTraverse()
{
}

/*
TreeNode::TreeNode()
{
	index = 0;
	data = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}
*/
TreeNode * TreeNode::searchNode(int nodeIndex)
{
	// 比对根节点
	if (this->index == nodeIndex)
	{
		return this;
	}

	// 比对左节点
	if (NULL != this->pLChild)
	{
		if (this->pLChild->index == nodeIndex)
		{
			return this->pLChild;
		}
	}

	// 比对右节点
	if (NULL != this->pRChild)
	{
		if (this->pRChild->index == nodeIndex)
		{
			return this->pRChild;
		}
	}

	return nullptr;
}

MyLinkTree::MyLinkTree(int n)
{
	// num里面的值是一棵树的先序遍历的值
	int num[] = { 1,2,4,8,0,0,9,0,0,5,10,0,0,11,0,0,3,6,12,0,0,13,0,0,7,14,0,0,15,0,0};
	int index = 0;
	m_pRoot = creatFullTree(m_pRoot,num, index);
}

MyLinkTree::~MyLinkTree()
{

}

TreeNode* MyLinkTree::creatFullTree(TreeNode* node ,int* num,int& index)
{
	if (num[index] == 0)
		return NULL;
	else
	{
		node = new TreeNode;
		node->data = num[index];
		node->pLChild = creatFullTree(node->pLChild, num, ++index);
		node->pRChild = creatFullTree(node->pRChild, num, ++index);
		return node;
	}
	

}

void MyLinkTree::preOrderTraverse() const
{
	cout << "前序遍历：";
	preOrderTraverse(m_pRoot);
	cout << endl;
}

void MyLinkTree::inOrderTraverse() const
{
	cout << "中序遍历：";
	inOrderTraverse(m_pRoot);
	cout << endl;
}

void MyLinkTree::postOrderTraverse() const
{
	cout << "后序遍历：";
	postOrderTraverse(m_pRoot);
	cout << endl;
}

void MyLinkTree::preOrderTraverse(TreeNode* root) const
{
	if (nullptr == root)
	{
		return;
	}
	else
	{
		// 操作
		cout << root->data << "->";

		// 更新递归变量以及进入深层次递归
		preOrderTraverse(root->pLChild);// 递归左子树
		preOrderTraverse(root->pRChild);// 递归右子树
	}
}

void MyLinkTree::inOrderTraverse(TreeNode* root) const
{
	if (nullptr == root)
	{
		return;
	}
	else
	{
		inOrderTraverse(root->pLChild);
		cout << root->data << "->";
		inOrderTraverse(root->pRChild);
	}
}

void MyLinkTree::postOrderTraverse(TreeNode * root) const
{
	if (nullptr == root)
	{
		return;
	}
	else
	{
		postOrderTraverse(root->pLChild);
		postOrderTraverse(root->pRChild);
		cout << root->data << "->";
	}
}

int MyLinkTree::treeDepth(TreeNode * node) const
{
	if (nullptr == node)
	{
		return 0;
	}
	
	int leftDepth = treeDepth(node->pLChild);
	int rightDepth = treeDepth(node->pRChild);
	return leftDepth>rightDepth ? leftDepth + 1 : rightDepth + 1;
}

int MyLinkTree::treeDepth() const
{
	return treeDepth(m_pRoot);
}

TreeNode * MyLinkTree::searchNode(int nodeIndex)
{
	if (nodeIndex < 0)
	{
		return nullptr;
	}

	return this->m_pRoot->searchNode(nodeIndex);
}

bool MyLinkTree::addNode(int nodeIndex, int direction, TreeNode * pNode)
{
	return false;
}

bool MyLinkTree::deleteNode(int nodeIndex, TreeNode * pNode)
{
	return false;
}

#endif