#pragma once
#include <chrono>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class MyString
{
public:
	static size_t CCtor; //ͳ�Ƶ��ÿ������캯���Ĵ���

public:
	// ���캯��
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

	// �������캯��
	MyString(const MyString& str) {
		CCtor++;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
	}
	// ������ֵ���� =������
	MyString& operator=(const MyString& str) {
		if (this == &str) // �������Ҹ�ֵ!!
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
	static size_t CCtor; //ͳ�Ƶ��ÿ������캯���Ĵ���
	static size_t MCtor; //ͳ�Ƶ����ƶ����캯���Ĵ���
	static size_t CAsgn; //ͳ�Ƶ��ÿ�����ֵ�����Ĵ���
	static size_t MAsgn; //ͳ�Ƶ����ƶ���ֵ�����Ĵ���

public:
	// ���캯��
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

	// �������캯��
	MyString2(const MyString2& str) {
		CCtor++;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
	}
	// �ƶ����캯��
	MyString2(MyString2&& str) noexcept
		:m_data(str.m_data) {
		MCtor++;
		str.m_data = nullptr; //����ָ��֮ǰ����Դ��
	}

	// ������ֵ���� =������
	MyString2& operator=(const MyString2& str) {
		CAsgn++;
		if (this == &str) // �������Ҹ�ֵ!!
			return *this;

		delete[] m_data;
		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
		return *this;
	}

	// �ƶ���ֵ���� =������
	MyString2& operator=(MyString2&& str) noexcept {
		MAsgn++;
		if (this == &str) // �������Ҹ�ֵ!!
			return *this;

		delete[] m_data;
		m_data = str.m_data;
		str.m_data = nullptr; //����ָ��֮ǰ����Դ��
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
	vecStr.reserve(1000); //�ȷ����1000���ռ䣬����ô�������õĴ�������Զ����1000
	for (int i = 0; i < 1000; i++) {
		vecStr.push_back(MyString("hello"));
	}
	cout << MyString::CCtor << endl;
}

void RValueTest2()
{

	vector<MyString2> vecStr;
	vecStr.reserve(1000); //�ȷ����1000���ռ�
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
	// ���캯��
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