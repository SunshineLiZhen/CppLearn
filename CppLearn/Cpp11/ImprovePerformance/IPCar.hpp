#pragma once
#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// 提升性能领域的汽车类
/// </summary>
class IPCar
{
	int* pI = new int(1);
public:
	IPCar()
	{
		cout << "IPCar 构造函数!" << endl;
	}
	
	~IPCar()
	{
		cout << "IPCar 析构函数!" << endl;
		delete pI;
	}
	
	//复制构造函数
	IPCar(const IPCar& other)
	{
		name = other.name;
		cout << "IPCar 复制构造函数!" << endl;
	}

	// 赋值运算符
	IPCar operator =(const IPCar& other)
	{
		IPCar tmp;
		tmp.name = other.name;
		cout << "IPCar 赋值运算符!" << endl;

		return tmp;
	}

	string name;
};


// 浅拷贝
class Cup
{
private:
	// 大内存模拟
	string m_name;
	vector<string> m_ObjList;
public:
	// 构造函数
	Cup()
	{
		cout << "House 构造函数!" << endl;
	}

	// 拷贝构造函数
	Cup(const Cup& other)
	{
		m_name = other.m_name;
		for (int i = 0; i < m_ObjList.size(); ++i)
		{
			m_ObjList[i] = other.m_ObjList[i];
		}
		cout << "House 拷贝构造函数!" << endl;
	}

	// 重载赋值运算符
	Cup operator=(const Cup& other)
	{
		Cup res;
		res.m_name = other.m_name;
		for (int i = 0; i < m_ObjList.size(); ++i)
		{
			res.m_ObjList[i] = other.m_ObjList[i];
		}

		cout << "House 赋值运算符!" << endl;

		return res;
	}
};

class FastCup
{
private:
	// 大内存模拟
	string m_name;
	vector<string> m_ObjList;
public:
	// 构造函数
	FastCup()
	{
		cout << "FastHouse 构造函数!" << endl;
	}

	FastCup(const FastCup&& other)
	{
		m_name = other.m_name;
	}
};