#pragma once
#include "MathRuleStrategy.hpp"
#include <iostream>

using namespace std;

/// <summary>
/// ��ѧ���㳡����
/// </summary>
class MathOperationContext
{
private:
	shared_ptr<IMathOperationStrategy> m_mathStrategy;

public:
	MathOperationContext() = default;

	/// <summary>
	/// ���ò���
	/// </summary>
	/// <param name="strategy"></param>
	void SetStrategy(shared_ptr<IMathOperationStrategy> strategy)
	{
		m_mathStrategy = strategy;
	}

	/// <summary>
	/// �������
	/// </summary>
	/// <param name="num1"></param>
	/// <param name="num2"></param>
	void Calculate(double num1, double num2)
	{
		m_mathStrategy->Calculate(num1, num2);

		//�������дһЩ���в���ͨ�õĴ��룬�����ӡ��־
		cout << "calculate:" << num1 << "-" << num2 << endl;
	}
   
private:

};

