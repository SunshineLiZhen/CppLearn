#pragma once

#include <iostream>

using namespace std;




class BaseClassV
{
public:
	virtual void PrintName() {}
};


class ChildClassV :public BaseClassV
{
private:
	int m_type;
public:
	void SetName(int type)
	{
		m_type = type;
	}

	void PrintName() override
	{
		cout << "My name is " << m_type << endl;
	}
};

class BV2
{
public:
	BV2() = default;
};

class CV2:public BV2
{
public:
	virtual void PrintName() {}
};

class CV3 :public CV2
{
public:

};

/// 虚函数测试类
class VirtualFunctionLearn
{
public:
	void Test()
	{
		// 测试类的大小
		// 基类中也有虚函数表指针
		cout << "基类大小：" << sizeof(BaseClassV) << endl;// 8个字节
		cout << "子类大小" << sizeof(ChildClassV) << endl; // 16个字节

		// 基类BV2中没有virtual函数，所以没有虚函数指针
		cout << "基类大小：" << sizeof(BV2) << endl;// 1个字节
		cout << "子类大小" << sizeof(CV2) << endl; // 8个字节
		cout << "子类大小" << sizeof(CV3) << endl; // 8个字节

		BaseClassV bv1;
		ChildClassV cA1, cA2;
		cA1.SetName(1);
		cA2.SetName(2);

		// 每个具有虚函数的类都有一个虚函数表，基类BaseClassV有一个，派生类ChildClassV也有一个。两者不是一个。
		cout << *((int*)(&bv1)) << endl;//1418468736
		cout << *((int*)(&cA1)) << endl;//1418468760
		cout << *((int*)(&cA2)) << endl;//1418468760

		BaseClassV* pB = &cA1;
		pB->PrintName();
		pB = &cA2;
		pB->PrintName();
	}

};