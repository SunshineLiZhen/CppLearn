#pragma once
#include <iostream>
#include <shared_mutex>
#include <string>
using namespace std;

class C17Learn
{
public:
	void StringViewLearn()
	{
		// string_view 
		string_view sv1 = "hello china!";

	}
private:

	/// <summary>
	/// shared_mutex：在多个只读线程和一个写线程的情况下，shared_mutex比mutex快一倍。
	/// </summary>
	struct GoodsStock {
		mutable std::shared_mutex m_mutex;
		int m_count;

		GoodsStock() { m_count = 0; }

		int read() const
		{
			std::shared_lock<std::shared_mutex> lock(m_mutex);
			return m_count;
		}

		void write()
		{
			std::unique_lock<std::shared_mutex> lock(m_mutex);
			m_count += 1;
		}
	};
};

// 这样定义变量，如果其他文件2次及以上引用了这个文件，就会导致变量x，重复定义。
//int x;

// 内联变量：多个翻译单元内的重复声明，C++链接器只选择一个
// 这样编译器就不报错了
inline int y;