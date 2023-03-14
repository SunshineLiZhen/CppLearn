#pragma once
#include <iostream>
#include <vector>

using namespace std;


/// <summary>
/// 苹果类
/// </summary>
class Apple
{
private:
	string m_name;

public:
	Apple(string name):m_name(name)
	{
		cout << "Apple 构造函数!" << endl;
	}
	
	~Apple()
	{
		cout << "Apple 析构函数!" << endl;
	}
	
	//复制构造函数
	Apple(const Apple& other)
	{
		m_name = other.m_name;
		cout << "Apple 复制构造函数!" << endl;
	}

	// 赋值运算符
	Apple operator =(const Apple& other)
	{
		Apple tmp("");
		tmp.m_name = other.m_name;
		cout << "Apple 赋值运算符!" << endl;

		return tmp;
	}

};
