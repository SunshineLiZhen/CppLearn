#pragma once
#include <iostream>
#include "IPCar.hpp"
#include "Apple.hpp"

using namespace std;

/// <summary>
/// 移动操作
/// </summary>
class MoveOperater
{
public:
	void Test()
	{
		Test1();
		Test2();
		Test3();
	}
	// move函数将一个左值变为右值
	void Test1()
	{
		IPCar car1;
		car1.name = "car1";
		IPCar car2 = move(car1);
		car2.name = "car2";
		// 这样离开函数后会调用两次析构函数，这是有问题的

		int a;
		int b = move(a);
		a = 10;
		b = 22;
		// 栈内存，这样写，离开函数后，不会报错。？？？
	}

	void Test2()
	{
		// 指针之间赋值就是移动，不需要move
		IPCar* pCar1 = new IPCar();
		IPCar* pCar2 = pCar1;

		delete pCar1;
	}
	
	void Test3()
	{
		Apple a1("apple1");
		CopyApple(move(a1));
	}
	void CopyApple(Apple&& ap)
	{

	}
};

