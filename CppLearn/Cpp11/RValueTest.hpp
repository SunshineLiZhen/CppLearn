#pragma once
#include <chrono>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class MyString
{
public:
	static size_t CCtor; //统计调用拷贝构造函数的次数

public:
	// 构造函数
	MyString(const char* cstr = 0) {
		if (cstr) {
			m_data = new char[strlen(cstr) + 1];
			strcpy(m_data, cstr);
		}
		else {
			m_data = new char[1];
			*m_data = '\0';
		}
	}

	// 拷贝构造函数
	MyString(const MyString& str) {
		CCtor++;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
	}
	// 拷贝赋值函数 =号重载
	MyString& operator=(const MyString& str) {
		if (this == &str) // 避免自我赋值!!
			return *this;

		delete[] m_data;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
		return *this;
	}

	~MyString() {
		delete[] m_data;
	}

	char* get_c_str() const { return m_data; }
private:
	char* m_data;
};
size_t MyString::CCtor = 0;



class MyString2
{
public:
	static size_t CCtor; //统计调用拷贝构造函数的次数
	static size_t MCtor; //统计调用移动构造函数的次数
	static size_t CAsgn; //统计调用拷贝赋值函数的次数
	static size_t MAsgn; //统计调用移动赋值函数的次数

public:
	// 构造函数
	MyString2(const char* cstr = 0) {
		if (cstr) {
			m_data = new char[strlen(cstr) + 1];
			strcpy(m_data, cstr);
		}
		else {
			m_data = new char[1];
			*m_data = '\0';
		}
	}

	// 拷贝构造函数
	MyString2(const MyString2& str) {
		CCtor++;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
	}
	// 移动构造函数
	MyString2(MyString2&& str) noexcept
		:m_data(str.m_data) {
		MCtor++;
		str.m_data = nullptr; //不再指向之前的资源了
	}

	// 拷贝赋值函数 =号重载
	MyString2& operator=(const MyString2& str) {
		CAsgn++;
		if (this == &str) // 避免自我赋值!!
			return *this;

		delete[] m_data;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
		return *this;
	}

	// 移动赋值函数 =号重载
	MyString2& operator=(MyString2&& str) noexcept {
		MAsgn++;
		if (this == &str) // 避免自我赋值!!
			return *this;

		delete[] m_data;
		m_data = str.m_data;
		str.m_data = nullptr; //不再指向之前的资源了
		return *this;
	}

	~MyString2() {
		delete[] m_data;
	}

	char* get_c_str() const { return m_data; }
private:
	char* m_data;
};
size_t MyString2::CCtor = 0;
size_t MyString2::MCtor = 0;
size_t MyString2::CAsgn = 0;
size_t MyString2::MAsgn = 0;

void RValueTest()
{
	vector<MyString> vecStr;
	vecStr.reserve(1000); //先分配好1000个空间，不这么做，调用的次数可能远大于1000
	for (int i = 0; i < 1000; i++) {
		vecStr.push_back(MyString("hello"));
	}
	cout << MyString::CCtor << endl;
}

void RValueTest2()
{

	vector<MyString2> vecStr;
	vecStr.reserve(1000); //先分配好1000个空间
	for (int i = 0; i < 1000; i++) {
		vecStr.push_back(MyString2("hello"));
	}
	cout << "CCtor = " << MyString2::CCtor << endl;
	cout << "MCtor = " << MyString2::MCtor << endl;
	cout << "CAsgn = " << MyString2::CAsgn << endl;
	cout << "MAsgn = " << MyString2::MAsgn << endl;
}


class AA
{
public:
	AA(const char* str) {
		if (str != nullptr)
		{
			m_data = new char[strlen(str) + 1];
			strcpy(m_data, str);
		}
	}
	// 构造函数
	AA(AA& other)
	{
		m_data = other.m_data;
		other.m_data = nullptr;
	}
	~AA()
	{
		delete[] m_data;
	}

	void Print()
	{
		if (m_data == nullptr)
		{
			cout << "null ptr" << endl;
		}
		else 
		{
			cout << m_data << endl;
		}
	}
private:
	char * m_data = nullptr;
};

void RValueTest3()
{
	AA a1("china");
	AA a2(a1);
	a1.Print();


	char* pname = new char[10];
	strcpy(pname, "china");
	char* && pp = std::move(pname);
	char*&& xx = std::move(pp);
	if(pp != nullptr)
	delete pp;
	delete xx;

}