#include "FunctionalLearn.h"
#include <string>
#include <iostream>
using namespace std;

typedef void(*pFunc)(const string &s);

// 函数指针
void foo(const string &s)
{
	cout << s << endl;
}

FunctionalLearn::FunctionalLearn()
{
}

FunctionalLearn::~FunctionalLearn()
{
}

void FunctionalLearn::memoeryFunction(int i)
{
	cout << i << endl;
}

void FunctionalLearn::test()
{
	// 普通函数
	// 1.使用函数指针调用函数
	void (*fun1)(const string&) = &foo;
	fun1("china");

	// 2.使用函数对象调用函数
	function<void(const string &)> fun2 = &foo;
	fun2("china");

	// 成员函数
	// 3.使用函数适配器
	//如果使用bind绑定某个值，那么该函数等于该参数消失了。如果需要保留，需要使用占位符占住位置。
	//在这个例子中，foo原本有两个参数，我们把隐式参数绑定某个对象地址，所以只剩下一个地址。
	function<void(int)> fun3 = bind(&FunctionalLearn::memoeryFunction, this, placeholders::_1);
	fun3(2);

	//在使用STL算法时，其中到比较函数，如果是成员函数。模板拿不到成员函数到指针，这时候需要用bind


}

unsigned short zigZagDecode(unsigned short value)
{
	return (value >> 1) ^ (-(value & 1));
}

void zigZagDeltaDecode(unsigned short uBuffer[], unsigned short vBufer[], unsigned short heightBuffer[],int count)
{
	unsigned short u = 0;
	unsigned short v = 0;
	for (int i = 0; i < count; ++i)
	{
		u += zigZagDecode(uBuffer[i]);
		v += zigZagDecode(uBuffer[i]);
	}
}