#pragma once
#include <chrono>
#include <vector>
#include <iostream>
#include "TimeExpandCount.h"

using namespace std;

class StudentInfor
{
public:
	// 构造函数
	StudentInfor()
	{
		cout << "调用构造函数" << endl;
	}

	// 复制构造函数
	StudentInfor(const StudentInfor& other)
	{
		cout << "调用复制构造函数" << endl;
	}

	// 移动构造函数
	StudentInfor(StudentInfor&& other) noexcept
	{
		cout << "调用移动构造函数" << endl;
	}
};

/// <summary>
/// 右值的应用
/// 核心原理：降低复制带来的内存，cpu，时间消耗
/// 1.函数返回值
/// 3.对象复制：复制后原来的对象不需要了，或者会被销毁。这个时候用对象移动会提高效率
/// </summary>
class RValueApplication
{
public:
	//节省大内存对象复制时间
	void UseMoveConstructer()
	{
		vector<StudentInfor> students;

        // 调用构造函数
		StudentInfor s1;
        StudentInfor s2;
        cout << "-------------------------------" << endl;

		//调用了一次复制构造函数，复制构造函数浪费时间
		students.push_back(s1);
        cout << "-------------------------------" << endl;

		// 调用2次移动构造函数，但是性能不如emplace_back
		students.push_back(move(s1));
        cout << "-------------------------------" << endl;

		// 调用3次移动构造函数
		students.emplace_back(move(s2));
        cout << "-------------------------------" << endl;
	}
	
	// 性能测试
	void PerformanceTest()
	{
        TimeExpandCount tc;
        std::vector<std::string> v;
        int count = 10000000;
        v.reserve(count);       //预分配十万大小，排除掉分配内存的时间

        {
            tc.StartCount();
            for (int i = 0; i < count; i++)
            {
                std::string temp("ceshi");
                v.push_back(temp);// push_back(const string&)，参数是左值引用
            }
            auto total = tc.StopCount();
            cout << "push_back copy(string):" << total << endl;
        }

        v.clear();
        {
            tc.StartCount();
            for (int i = 0; i < count; i++)
            {
                std::string temp("ceshi");
                v.push_back(std::move(temp));// push_back(string &&), 参数是右值引用
            }
            cout << "push_back move(string) :" << tc.StopCount() << endl;
        }

        v.clear();
        {
            tc.StartCount();
            for (int i = 0; i < count; i++)
            {
                v.push_back(std::string("ceshi"));// push_back(string &&), 参数是右值引用
            }
            cout << "push_back(string):" << tc.StopCount() << endl;

        }

        v.clear();
        {
            tc.StartCount();
            for (int i = 0; i < count; i++)
            {
                v.push_back("ceshi");// push_back(string &&), 参数是右值引用
            }
            cout << "push_back(c string):" << tc.StopCount() << endl;

        }

        v.clear();
        {
            tc.StartCount();

            for (int i = 0; i < count; i++)
            {
                v.emplace_back("ceshi");// 只有一次构造函数，不调用拷贝构造函数，速度最快
            }
            cout << "emplace_back(c string):" << tc.StopCount() << endl;
        }
	}

};


