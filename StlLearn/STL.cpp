#include "Stl.h"
#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;

STLLearn::STLLearn()
{
	cout << "************************************STL学习**********************************" << endl;
}


STLLearn::~STLLearn()
{
	cout << "************************************STL学习**********************************" << endl;
}

void STLLearn::vectorExample()
{
	/// 初始化 
	vector<int> vEmpty;//此时的vector是空的没有元素的
	vector<int> vInt(4);//定义4个元素的vector

	/// 插入 删除 
	for (int i = 0; i < 10; ++i)
	{
		// 在最后位置插入元素
		vInt.push_back(i);
	}

	// 遍历
	cout << "vector   push：";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	// 删掉最后一个元素
	vInt.pop_back();

	cout << "vector    pop：";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	// 插入一个元素
	vInt.insert(vInt.begin() + 4, 100);
	cout << "vector insert：";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	// 删除一个元素
	vInt.erase(vInt.begin() + 4);

	cout << "vector  erase：";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;

	/// 查找删除 
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		if (*it == 9)
		{
			it = vInt.erase(it);
		}
	}

	cout << "vector查找删除：";
	for (auto it = vInt.begin(); it != vInt.end(); it++)
	{
		cout << " " << *it;
	}
	cout << endl;
}

void STLLearn::mapExample()
{
	/// 初始化
	map<int, string> mapStudent;

	/// 插入
	// 当map中有这个关键字时，insert操作是插入数据不了的
	mapStudent.insert(pair<int, string>(1, "student-one"));
	mapStudent.insert(map<int, string>::value_type(2, "student-two"));
	mapStudent.insert(map<int, string>::value_type(3, "student-three"));
	mapStudent.insert(map<int, string>::value_type(4, "student-four"));
	mapStudent.insert(map<int, string>::value_type(5, "student-five"));
	// 使用数组下标可以覆盖以前该关键字对 应的值，用程序说明
	mapStudent[3] = "jim";

	/// 遍历
	cout << "mapStudent: " << endl;
	for (auto it = mapStudent.begin(); it != mapStudent.end(); ++it)
	{
		cout << it->first << "|" << it->second << endl;
	}
	cout << endl;

	/// 删除
	mapStudent.erase(3);// 使用key删除

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

	/// 查找，排序
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
