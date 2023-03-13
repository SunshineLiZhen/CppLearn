#pragma once
#include <iostream>


/// <summary>
/// 基类和派生类构造顺序：基类,派生类
/// 基类和派生类析构顺序：派生类，基类
/// 可以把基类和派生类想象成两个同心圆，基类在中间，派生类在外面。创建的时候从中间开始创建，销毁的时候从外到内开始创建。
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
