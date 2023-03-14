#pragma once
#include <iostream>
#include <vector>

using namespace std;


/// <summary>
/// ƻ����
/// </summary>
class Apple
{
private:
	string m_name;

public:
	Apple(string name):m_name(name)
	{
		cout << "Apple ���캯��!" << endl;
	}
	
	~Apple()
	{
		cout << "Apple ��������!" << endl;
	}
	
	//���ƹ��캯��
	Apple(const Apple& other)
	{
		m_name = other.m_name;
		cout << "Apple ���ƹ��캯��!" << endl;
	}

	// ��ֵ�����
	Apple operator =(const Apple& other)
	{
		Apple tmp("");
		tmp.m_name = other.m_name;
		cout << "Apple ��ֵ�����!" << endl;

		return tmp;
	}

};
