#pragma once
#include <iostream>
#include "Product.hpp"
#include "Factory.hpp"

using namespace std;

/// <summary>
/// Ӧ�ð���
/// �����Ĵ����ǹ̶��ģ���ʹ�õ��ǽӿڣ�û��ʹ�þ����ࡣ
/// ������Ϊ�µĲ�Ʒ���¸ı����
/// </summary>
class ApplyCase
{
private:
	shared_ptr<ISplitter> m_splitter = nullptr;
	shared_ptr<IFactory> m_factory = nullptr;

public:
	/// <summary>
	/// �仯���ܲ��ᱻ���������ǿ��԰����ϵ�һ���ط������������ط����ǲ���ġ�
	/// </summary>
	/// <param name="factory"></param>
	ApplyCase(shared_ptr<IFactory> factory)
	{
		m_factory = factory;
	}

	void Go()
	{
		m_splitter = m_factory->CreateSplitter();

		m_splitter->Split("");
	}
};






