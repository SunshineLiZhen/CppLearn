#pragma once
#include <iostream>
using namespace std;

/// <summary>
/// ��C++�ж��ڿ��������������һЩĬ�ϵĳ�Ա��������Ĭ�Ϲ��캯���ȡ�
/// ��ʱ�����������ɣ���ʱ�ֲ����ɣ�������ɻ��ң�����C++11�ó���Ա���Կ����Ƿ���Ҫ���������ɡ�
/// </summary>
class ControlDefaultMember
{
public:
	/// ��ʾȱʡ����
	ControlDefaultMember() = default;//�ñ�����Ĭ�������޲ι��캯��
	ControlDefaultMember(int year) :_year(year)    //������дȱʡֵ��ʱ�򣬾Ͳ���Ҫ�Լ���ȥʵ��һ��Ĭ�ϵ��޲ι��캯��
	{}

	void fun()
	{
		cout << "this is A" << endl;
	}

	/// ɾ��Ĭ�Ϻ�������ֹ���ã�
	// ��ֹ����������Ĭ�ϵĿ������캯���Լ���ֵ���������
	ControlDefaultMember (ControlDefaultMember&) = delete;
	ControlDefaultMember& operator=(const ControlDefaultMember) = delete;
private:
	int _year;

};


