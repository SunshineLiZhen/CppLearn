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
	//申请内存
	int *p = new int;//申请一个int类型的空间，具有默认初始值
	int *q = new int(10);//申请一个int类型的空间，人工赋值10
	int *w = new int[5];//申请5个int类型的空间，具有默认初始值
	if (NULL == p)
	{
		cout << "p申请失败" << endl;
		return;
	}
	if (NULL == q)
	{
		cout << "q申请失败" << endl;
		return;
	}
	if (NULL == w)
	{
		cout << "w申请失败" << endl;
		return;
	}
	//使用内存
	cout << "*p=" << *p << endl;
	cout << "*q=" << *q << endl;
	cout << "*w:";
	for (int i = 0; i < 5; ++i)
	{
		cout << *(w + i);
	}

	//释放内存
	delete p;  //释放内存，防止内存泄漏
	p = NULL;//防止再次使用，防止二次释放
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
