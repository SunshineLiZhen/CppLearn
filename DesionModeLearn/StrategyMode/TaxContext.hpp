#pragma once
#include "TaxStrategy.hpp"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

/// <summary>
/// 税收上下文类类
/// 使用策略模式替代if-else
/// </summary>
class TaxContext
{
private:
	vector <shared_ptr<ITaxStrategy>> m_taxStrategys;
public:
	TaxContext()
	{
		m_taxStrategys.push_back(shared_ptr<ITaxStrategy >(make_shared< USTax>()));
		m_taxStrategys.push_back(shared_ptr<ITaxStrategy >(make_shared< CNTax>()));
		//修改
	};

	/// <summary>
	/// 计算操作
	/// </summary>
	/// <param name="num1"></param>
	/// <param name="num2"></param>
	void Calculate(float price,string type)
	{
		auto strategy = getStrategy(type);
		strategy->Calculate(price);
	}
   
private:
	shared_ptr<ITaxStrategy > getStrategy(string type)
	{
		for (auto it : m_taxStrategys)
		{
			if (it->GetSupportType() == type)
			{
				return it;
			}
		}
		
	}
};

