#pragma once
#include <iostream>
#include "Product.hpp"
#include "Factory.hpp"

using namespace std;

/// <summary>
/// 应用案例
/// 这个类的代码是固定的，都使用的是接口，没有使用具体类。
/// 不会因为新的产品导致改变代码
/// </summary>
class ApplyCase
{
private:
	shared_ptr<ISplitter> m_splitter = nullptr;
	shared_ptr<IFactory> m_factory = nullptr;

public:
	/// <summary>
	/// 变化可能不会被消除，但是可以把他赶到一个地方。这样其他地方都是不变的。
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






