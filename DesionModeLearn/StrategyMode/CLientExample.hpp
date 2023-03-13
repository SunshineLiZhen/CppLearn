#pragma once
#include <iostream>
#include "MathRuleStrategy.hpp"
#include "MathOperationContext.hpp"

using namespace std;

class ClientExample
{
public:
	void Test()
	{
		shared_ptr< IMathOperationStrategy> mathStrategy = nullptr;

		double a = 10;
		double b = 21.2;
		double sum = 0;

		mathStrategy = make_shared<AddOperation>();
		sum = mathStrategy->Calculate(a, b);

		mathStrategy = make_shared<SubstractOperation>();
		sum = mathStrategy->Calculate(a, b);
	}

	/*
	* ��������ܴ�Ҿ��������ˣ�����������ĵ��ú�ֱ�ӵ��ò��Խӿڵķ�ʽ����ûʲô��ͬ����ô�����������ʲô�����أ�
����һ�£����ÿ������Ĳ��Զ���һ����Ҫִ�еĴ��룬���� System.out.println("ÿ�������඼��Ҫִ�еĴ���")����������Ҫ��ÿ�����������������룬
���������������࣬����԰ѹ��õĴ���д�ڸ�����
��ʵ�ʿ����У����ǵ���������������ṹʾ��ͼ��������˼򵥡����simple��ʵ�ʽ�Ϊ������������ǣ�
�ϲ�ĵ�����Ҫ��ӿ�֮����һ���Ľ����������Ŀ�����һЩ���ԣ�����һЩ�����������Ľ����������ýӿڱ�����Ե��ã�
���������ĵ�����������ڱ��С�����ص����Ի�һЩ�����ķ�����װ���������У���������ȥ�ͽӿڽ��и��ӵĽ��������ϲ�ĵ���ֻ��Ҫ�������Ĵ򽻵��Ϳ��ԡ�

����ģʽ������װ�㷨���ṩ�µ��㷨���뵽����ϵͳ�У�����ģʽ���������ں�ʱʹ�ú����㷨����ʲô�����ʹ��ʲô�㷨���ɿͻ��˾����ġ�

	*/
	void TestWithContext()
	{
		double a = 10;
		double b = 21.2;
		double sum = 0;

		shared_ptr< IMathOperationStrategy> mathStrategy = nullptr;
		mathStrategy = make_shared<AddOperation>();

		auto contex = new MathOperationContext();
		contex->SetStrategy(mathStrategy);
		contex->Calculate(a, b);

	}
};


