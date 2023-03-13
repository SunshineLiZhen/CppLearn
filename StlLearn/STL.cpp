#include "Stl.h"
#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

STLLearn::STLLearn()
{
	cout << "************************************STLѧϰ**********************************" << endl;
}


STLLearn::~STLLearn()
{
	cout << "************************************STLѧϰ**********************************" << endl;
}

void STLLearn::vectorExample()
{
	/// ��ʼ�� 
	vector<int> vEmpty;//��ʱ��vector�ǿյ�û��Ԫ�ص�
	vector<int> vInt(4);//����4��Ԫ�ص�vector

	/// ���� ɾ�� 
	for (int i = 0; i < 10; ++i)
	{
		// �����λ�ò���Ԫ��
		vInt.push_back(i);
	}

	// ����
	cout << "vector   push��";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	// ɾ�����һ��Ԫ��
	vInt.pop_back();

	cout << "vector    pop��";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	// ����һ��Ԫ��
	vInt.insert(vInt.begin() + 4, 100);
	cout << "vector insert��";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	// ɾ��һ��Ԫ��
	vInt.erase(vInt.begin() + 4);

	cout << "vector  erase��";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	/// ����ɾ�� 
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		if (*it == 9)
		{
			it = vInt.erase(it);
		}
	}

	cout << "vector����ɾ����";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
}

void STLLearn::mapExample()
{
	/// ��ʼ��
	map<int, string> mapStudent;

	/// ����
	// ��map��������ؼ���ʱ��insert�����ǲ������ݲ��˵�
	mapStudent.insert(pair<int, string>(1, "student-one"));
	mapStudent.insert(map<int, string>::value_type(2, "student-two"));
	mapStudent.insert(map<int, string>::value_type(3, "student-three"));
	mapStudent.insert(map<int, string>::value_type(4, "student-four"));
	mapStudent.insert(map<int, string>::value_type(5, "student-five"));
	// ʹ�������±���Ը�����ǰ�ùؼ��ֶ� Ӧ��ֵ���ó���˵��
	mapStudent[3] = "jim";

	/// ����
	cout << "mapStudent: " << endl;
	for (auto it = mapStudent.begin(); it != mapStudent.end(); ++it)
	{
		cout << it->first << "|" << it->second << endl;
	}
	cout << endl;

	/// ɾ��
	mapStudent.erase(3);// ʹ��keyɾ��

	for (auto it = mapStudent.begin(); it != mapStudent.end();)
	{
		if ("student-five" == it->second)
		{
			mapStudent.erase(it++);
		}
		else
		{
			it++;
		}
	}

	cout << "mapStudent: " << endl;
	for (auto it = mapStudent.begin(); it != mapStudent.end(); ++it)
	{
		cout << it->first << "|" << it->second << endl;
	}
	cout << endl;

	/// ���ң�����
}

int fun(MultClass function)
{
	return function(5, 6);
}

void STLLearn::functionalExample()
{
	MultClass mc;
	cout << "functional learn" << endl;
	cout << fun(mc) << endl;
	cout << MultClass()(3, 4) << endl;
}
