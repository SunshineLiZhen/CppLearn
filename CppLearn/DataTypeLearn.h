#pragma once
#include <iostream>
using namespace std;

class DATaTypeLearn
{
public:
	DATaTypeLearn();
	~DATaTypeLearn();

	void yinYongExample();

	//������Ϊ�����β�
	void  asXingCan(int &x,int &y);

	// ����ת��
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

