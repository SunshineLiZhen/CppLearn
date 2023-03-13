#pragma once
#include <iostream>
#include "ProductPTM.hpp"

using namespace std;

/// <summary>
/// 创建当前对象的克隆
/// 某些结构比较复杂的对象，直接创建对象的代价比较大时，则采用这种模式
/// 不常用
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
		// 不能直接使用m_splitter,要创建出一个新对象
		auto splitter = m_splitter = m_splitter->Clone();

		splitter->Split("");
	}
};






