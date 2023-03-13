#pragma once
#include "MathRuleStrategy.hpp"
#include <iostream>

using namespace std;

/// <summary>
/// 数学运算场景类
/// </summary>
class MathOperationContext
{
private:
	shared_ptr<IMathOperationStrategy> m_mathStrategy;

public:
	MathOperationContext() = default;

	/// <summary>
	/// 设置策略
	/// </summary>
	/// <param name="strategy"></param>
	void SetStrategy(shared_ptr<IMathOperationStrategy> strategy)
	{
		m_mathStrategy = strategy;
	}

	/// <summary>
	/// 计算操作
	/// </summary>
	/// <param name="num1"></param>
	/// <param name="num2"></param>
	void Calculate(double num1, double num2)
	{
		m_mathStrategy->Calculate(num1, num2);

		//这里可以写一些所有策略通用的代码，比如打印日志
		cout << "calculate:" << num1 << "-" << num2 << endl;
	}
   
private:

};

