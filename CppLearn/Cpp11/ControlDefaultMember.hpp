#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// 在C++中对于空类编译器会生成一些默认的成员函数，如默认构造函数等。
/// 有时编译器会生成，有时又不生成，容易造成混乱，于是C++11让程序员可以控制是否需要编译器生成。
/// </summary>
class ControlDefaultMember
{
public:
	/// 显示缺省函数
	ControlDefaultMember() = default;//让编译器默认生成无参构造函数
	ControlDefaultMember(int year) :_year(year)    //这样不写缺省值的时候，就不需要自己在去实现一个默认的无参构造函数
	{}

	void fun()
	{
		cout << "this is A" << endl;
	}

	/// 删除默认函数（禁止调用）
	// 禁止编译器生成默认的拷贝构造函数以及赋值运算符重载
	ControlDefaultMember (ControlDefaultMember&) = delete;
	ControlDefaultMember& operator=(const ControlDefaultMember) = delete;
private:
	int _year;

};


