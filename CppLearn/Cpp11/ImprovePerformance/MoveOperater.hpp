#pragma once
#include <iostream>
#include "IPCar.hpp"
#include "Apple.hpp"

using namespace std;

/// <summary>
/// �ƶ�����
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
	// move������һ����ֵ��Ϊ��ֵ
	void Test1()
	{
		IPCar car1;
		car1.name = "car1";
		IPCar car2 = move(car1);
		car2.name = "car2";
		// �����뿪�����������������������������������

		int a;
		int b = move(a);
		a = 10;
		b = 22;
		// ջ�ڴ棬����д���뿪�����󣬲��ᱨ��������
	}

	void Test2()
	{
		// ָ��֮�丳ֵ�����ƶ�������Ҫmove
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

