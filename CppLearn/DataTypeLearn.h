#pragma once
#include <iostream>
using namespace std;

class DATaTypeLearn
{
public:
	DATaTypeLearn();
	~DATaTypeLearn();

	void yinYongExample();

	//引用作为函数形参
	void  asXingCan(int &x,int &y);

	// 类型转换
	void typeConvertExample();
};

class A {
public:
	virtual void test() 
	{
		cout << "ATest()" << endl;
	};
};
class B :public A 
{
public:
	void bOnly() { cout << "bOnly()" << endl; }
};
class C {};

