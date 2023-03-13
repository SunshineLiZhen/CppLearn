#pragma once
#include <iostream>
#include "ProductPTM.hpp"

using namespace std;

/// <summary>
/// ������ǰ����Ŀ�¡
/// ĳЩ�ṹ�Ƚϸ��ӵĶ���ֱ�Ӵ�������Ĵ��۱Ƚϴ�ʱ�����������ģʽ
/// ������
/// </summary>
class ApplyCase
{
private:
	shared_ptr<ISplitterPTM> m_splitter = nullptr;

public:
	ApplyCase(shared_ptr<ISplitterPTM> product)
	{
		m_splitter = product;
	}

	void Go()
	{
		// ����ֱ��ʹ��m_splitter,Ҫ������һ���¶���
		auto splitter = m_splitter = m_splitter->Clone();

		splitter->Split("");
	}
};






