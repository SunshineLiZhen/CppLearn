#pragma once
#include <iostream>
#include "Product.hpp"

using namespace std;

///
/// 工厂模式优点
/// 1.封装变化，创建产品逻辑有可能变化，封装成工厂类后，创建逻辑的变更对调用者透明
/// 2.隔离复杂性：封装复杂的创建逻辑，调用者无需了解如何创建对象。
/// 3.代码复用：创建代码抽离到独立的工厂类之后可以复用。
/// 4.控制复杂度：将创建代码抽离出来，让原本的函数或类职责更单一，代码更简洁。
/// 6.符合开闭原则：新增产品不需要修改原有代码，扩展就可以。
/// 

/// <summary>
/// 抽象工厂
/// </summary>
class IFactory
{
public:
	virtual shared_ptr<ISplitter> CreateSplitter() = 0;
};


/// <summary>
/// 二进制分割器工厂
/// </summary>
class BinaryFactory :public IFactory
{
public:
	virtual shared_ptr<ISplitter> CreateSplitter() override
	{
		return make_shared<BinarySplitter>();
	}
};


/// <summary>
/// 文本分割器工厂
/// </summary>
class TxtFactory :public IFactory
{
public:
	virtual shared_ptr<ISplitter> CreateSplitter() override
	{
		return make_shared<TxtSplitter>();
	}
};


/// <summary>
/// 图片分割器工厂
/// </summary>
class PictureFactory :public IFactory
{
public:
	virtual shared_ptr<ISplitter> CreateSplitter() override
	{
		return make_shared<BinarySplitter>();
	}
};

/// <summary>
/// 视频分割器工厂
/// </summary>
class VideoFactory :public IFactory
{
public:
	virtual shared_ptr<ISplitter> CreateSplitter() override
	{
		return make_shared<BinarySplitter>();
	}
};

