#pragma once
#include <functional>

/* 函数作为参数学习
 * 方法1：全局函数
 * 方法2：STL 函数对象
 * 方法3：bind
*/

class FunctionalLearn
{
public:
	FunctionalLearn();
	~FunctionalLearn();

	// 成员函数有一个隐藏参数this指针
	void memoeryFunction(int i);
	void test();
};

