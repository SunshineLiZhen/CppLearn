#pragma once
#include <chrono>
#include <vector>
#include <iostream>
#include "TimeExpandCount.h"

using namespace std;

class StudentInfor
{
public:
	// ���캯��
	StudentInfor()
	{
		cout << "���ù��캯��" << endl;
	}

	// ���ƹ��캯��
	StudentInfor(const StudentInfor& other)
	{
		cout << "���ø��ƹ��캯��" << endl;
	}

	// �ƶ����캯��
	StudentInfor(StudentInfor&& other) noexcept
	{
		cout << "�����ƶ����캯��" << endl;
	}
};

/// <summary>
/// ��ֵ��Ӧ��
/// ����ԭ�����͸��ƴ������ڴ棬cpu��ʱ������
/// 1.��������ֵ
/// 3.�����ƣ����ƺ�ԭ���Ķ�����Ҫ�ˣ����߻ᱻ���١����ʱ���ö����ƶ������Ч��
/// </summary>
class RValueApplication
{
public:
	//��ʡ���ڴ������ʱ��
	void UseMoveConstructer()
	{
		vector<StudentInfor> students;

        // ���ù��캯��
		StudentInfor s1;
        StudentInfor s2;
        cout << "-------------------------------" << endl;

		//������һ�θ��ƹ��캯�������ƹ��캯���˷�ʱ��
		students.push_back(s1);
        cout << "-------------------------------" << endl;

		// ����2���ƶ����캯�����������ܲ���emplace_back
		students.push_back(move(s1));
        cout << "-------------------------------" << endl;

		// ����3���ƶ����캯��
		students.emplace_back(move(s2));
        cout << "-------------------------------" << endl;
	}
	
	// ���ܲ���
	void PerformanceTest()
	{
        TimeExpandCount tc;
        std::vector<std::string> v;
        int count = 10000000;
        v.reserve(count);       //Ԥ����ʮ���С���ų��������ڴ��ʱ��

        {
            tc.StartCount();
            for (int i = 0; i < count; i++)
            {
                std::string temp("ceshi");
                v.push_back(temp);// push_back(const string&)����������ֵ����
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
                v.push_back(std::move(temp));// push_back(string &&), ��������ֵ����
            }
            cout << "push_back move(string) :" << tc.StopCount() << endl;
        }

        v.clear();
        {
            tc.StartCount();
            for (int i = 0; i < count; i++)
            {
                v.push_back(std::string("ceshi"));// push_back(string &&), ��������ֵ����
            }
            cout << "push_back(string):" << tc.StopCount() << endl;

        }

        v.clear();
        {
            tc.StartCount();
            for (int i = 0; i < count; i++)
            {
                v.push_back("ceshi");// push_back(string &&), ��������ֵ����
            }
            cout << "push_back(c string):" << tc.StopCount() << endl;

        }

        v.clear();
        {
            tc.StartCount();

            for (int i = 0; i < count; i++)
            {
                v.emplace_back("ceshi");// ֻ��һ�ι��캯���������ÿ������캯�����ٶ����
            }
            cout << "emplace_back(c string):" << tc.StopCount() << endl;
        }
	}

};


