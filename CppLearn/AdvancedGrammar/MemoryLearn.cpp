#include "stdafx.h"
#include "MemoryLearn.h"
using namespace std;

MemoryLearn::MemoryLearn()
{
}


MemoryLearn::~MemoryLearn()
{
}

void MemoryLearn::heapExample()
{
	//�����ڴ�
	int *p = new int;//����һ��int���͵Ŀռ䣬����Ĭ�ϳ�ʼֵ
	int *q = new int(10);//����һ��int���͵Ŀռ䣬�˹���ֵ10
	int *w = new int[5];//����5��int���͵Ŀռ䣬����Ĭ�ϳ�ʼֵ
	if (NULL == p)
	{
		cout << "p����ʧ��" << endl;
		return;
	}
	if (NULL == q)
	{
		cout << "q����ʧ��" << endl;
		return;
	}
	if (NULL == w)
	{
		cout << "w����ʧ��" << endl;
		return;
	}
	//ʹ���ڴ�
	cout << "*p=" << *p << endl;
	cout << "*q=" << *q << endl;
	cout << "*w:";
	for (int i = 0; i < 5; ++i)
	{
		cout << *(w + i);
	}

	//�ͷ��ڴ�
	delete p;  //�ͷ��ڴ棬��ֹ�ڴ�й©
	p = NULL;//��ֹ�ٴ�ʹ�ã���ֹ�����ͷ�
	delete q;  
	q = NULL;
	delete []w; 
	w = NULL;

}

void MemoryLearn::vectorExample()
{
	vector<int> vTest;
	for (int i = 0; i < 100; ++i)
	{
		vTest.push_back(i);
		cout << "capacity: " << vTest.capacity() << "size= " << vTest.size() << endl;
	}
}
