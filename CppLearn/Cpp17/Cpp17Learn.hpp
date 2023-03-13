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
	/// shared_mutex���ڶ��ֻ���̺߳�һ��д�̵߳�����£�shared_mutex��mutex��һ����
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

// ���������������������ļ�2�μ���������������ļ����ͻᵼ�±���x���ظ����塣
//int x;

// ����������������뵥Ԫ�ڵ��ظ�������C++������ֻѡ��һ��
// �����������Ͳ�������
inline int y;