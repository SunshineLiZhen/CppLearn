#pragma once
#include <iostream>
#include <shared_mutex>

using namespace std;

class Cpp14Learn
{
public:
	// ����auto����ֵ 
	auto TestAutoReturn()
	{
		int i = 2;
		return i;
	}

	/// ����lambda���ʽ��auto����֧��
	void TestLambda14()
	{
		// ��C14�У�lanbd���ʽ
		//c11
		auto fun1 = [](int a) { return a; };

		// c14
		auto fun2 = [](auto a) {return a; };

		fun1(11);
		//fun1("sss");// �﷨����

		fun2(11);
		fun2("china");
		fun2(2.0);
	}

	/// ����make_unique<>
	void TestUniquePtr()
	{
		unique_ptr<int> pInt = make_unique<int>();
	}

	/// ������д��
	void TestReadAndWriteLock()
	{

	}

	/// <summary>
	/// ��������Ļ�����
	/// </summary>
	struct GoodsStock {
		mutable std::shared_timed_mutex m_mutex;
		int m_count;

		GoodsStock() { m_count = 0; }

		int read() const 
		{
			std::shared_lock<std::shared_timed_mutex> loc(m_mutex);
			return m_count;
		}

		void write() 
		{
			std::unique_lock<std::shared_timed_mutex> lock(m_mutex);
			m_count += 1;
		}
	};
};