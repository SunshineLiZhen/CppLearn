#pragma once
#include <iostream>
#include <shared_mutex>

using namespace std;

class Cpp14Learn
{
public:
	// 新增auto返回值 
	auto TestAutoReturn()
	{
		int i = 2;
		return i;
	}

	/// 新增lambda表达式对auto参数支持
	void TestLambda14()
	{
		// 在C14中，lanbd表达式
		//c11
		auto fun1 = [](int a) { return a; };

		// c14
		auto fun2 = [](auto a) {return a; };

		fun1(11);
		//fun1("sss");// 语法错误

		fun2(11);
		fun2("china");
		fun2(2.0);
	}

	/// 新增make_unique<>
	void TestUniquePtr()
	{
		unique_ptr<int> pInt = make_unique<int>();
	}

	/// 新增读写锁
	void TestReadAndWriteLock()
	{

	}

	/// <summary>
	/// 货物存量的互斥锁
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