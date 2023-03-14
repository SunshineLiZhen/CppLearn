#pragma once
#include <iostream>
#include <vector>

using namespace std;

/// <summary>
/// �������������������
/// </summary>
class IPCar
{
	int* pI = new int(1);
public:
	IPCar()
	{
		cout << "IPCar ���캯��!" << endl;
	}
	
	~IPCar()
	{
		cout << "IPCar ��������!" << endl;
		delete pI;
	}
	
	//���ƹ��캯��
	IPCar(const IPCar& other)
	{
		name = other.name;
		cout << "IPCar ���ƹ��캯��!" << endl;
	}

	// ��ֵ�����
	IPCar operator =(const IPCar& other)
	{
		IPCar tmp;
		tmp.name = other.name;
		cout << "IPCar ��ֵ�����!" << endl;

		return tmp;
	}

	string name;
};


// ǳ����
class Cup
{
private:
	// ���ڴ�ģ��
	string m_name;
	vector<string> m_ObjList;
public:
	// ���캯��
	Cup()
	{
		cout << "House ���캯��!" << endl;
	}

	// �������캯��
	Cup(const Cup& other)
	{
		m_name = other.m_name;
		for (int i = 0; i < m_ObjList.size(); ++i)
		{
			m_ObjList[i] = other.m_ObjList[i];
		}
		cout << "House �������캯��!" << endl;
	}

	// ���ظ�ֵ�����
	Cup operator=(const Cup& other)
	{
		Cup res;
		res.m_name = other.m_name;
		for (int i = 0; i < m_ObjList.size(); ++i)
		{
			res.m_ObjList[i] = other.m_ObjList[i];
		}

		cout << "House ��ֵ�����!" << endl;

		return res;
	}
};

class FastCup
{
private:
	// ���ڴ�ģ��
	string m_name;
	vector<string> m_ObjList;
public:
	// ���캯��
	FastCup()
	{
		cout << "FastHouse ���캯��!" << endl;
	}

	FastCup(const FastCup&& other)
	{
		m_name = other.m_name;
	}
};