#pragma once
#include <iostream>


/// <summary>
/// ����������๹��˳�򣺻���,������
/// ���������������˳�������࣬����
/// ���԰ѻ�������������������ͬ��Բ���������м䣬�����������档������ʱ����м俪ʼ���������ٵ�ʱ����⵽�ڿ�ʼ������
/// </summary>
class BaseClassA
{
public:
	BaseClassA() 
	{
		std::cout << "BaseClassA()" << std::endl;
	}
};

class ChildClassA:public BaseClassA
{
public:
	ChildClassA()
	{
		std::cout << "ChildClassA()" << std::endl;

	}
};



class ClassLearn
{
public:
	ClassLearn() = default;

	


private:
};

inline int i;
