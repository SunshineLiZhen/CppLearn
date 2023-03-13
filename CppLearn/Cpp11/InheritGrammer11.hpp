#pragma once

class InheritGrammer11
{
public:
};


/// <summary>
/////////////////////////////////////////////////////////////////////////////////////// final关键字学习
/// </summary>
class Car final
{
public:
	void GetName() {};

};

// 不允许继承final类，语法错误
//class Bus :Car
//{
//
//};

class Animal
{
public:
	virtual void GetName() final{}
};

class Dog :public Animal
{
public:
	// 不允许重写final虚函数，语法错误
	//virtual void GetName() {}
};


/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////override学习  
/// 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错
/// </summary>
class Student
{
public:
	virtual void GetName() {}
};

class ZhangStudent:public Student
{
public:
	virtual void GetName() override {}
};