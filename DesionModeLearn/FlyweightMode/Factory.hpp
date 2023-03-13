#pragma once
#include <iostream>
#include "Product.hpp"

using namespace std;

///
/// ����ģʽ�ŵ�
/// 1.��װ�仯��������Ʒ�߼��п��ܱ仯����װ�ɹ�����󣬴����߼��ı���Ե�����͸��
/// 2.���븴���ԣ���װ���ӵĴ����߼��������������˽���δ�������
/// 3.���븴�ã�����������뵽�����Ĺ�����֮����Ը��á�
/// 4.���Ƹ��Ӷȣ���������������������ԭ���ĺ�������ְ�����һ���������ࡣ
/// 6.���Ͽ���ԭ��������Ʒ����Ҫ�޸�ԭ�д��룬��չ�Ϳ��ԡ�
/// 

/// <summary>
/// ���󹤳�
/// </summary>
class IFactory
{
public:
	virtual shared_ptr<ISplitter> CreateSplitter() = 0;
};


/// <summary>
/// �����Ʒָ�������
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
/// �ı��ָ�������
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
/// ͼƬ�ָ�������
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
/// ��Ƶ�ָ�������
/// </summary>
class VideoFactory :public IFactory
{
public:
	virtual shared_ptr<ISplitter> CreateSplitter() override
	{
		return make_shared<BinarySplitter>();
	}
};

