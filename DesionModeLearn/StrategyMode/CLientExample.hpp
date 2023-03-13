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
	* 到这里，可能大家就有疑问了，这边用上下文调用和直接调用策略接口的方式好像没什么不同，那么这个上下文有什么作用呢？
试想一下，如果每个具体的策略都有一个需要执行的代码，例如 System.out.println("每个策略类都需要执行的代码")，这样你需要再每个策略类添加这个代码，
如果有上下文这个类，你可以把公用的代码写在该类中
在实际开发中，我们的需求往往不会像结构示意图那样，如此简单、如此simple。实际较为常见的情况就是：
上层的调用需要与接口之间有一定的交互。交互的可能是一些属性，或是一些方法。这样的交互往往会让接口变的难以调用；
于是上下文的引入就是势在必行。将相关的属性或一些公共的方法封装到上下文中，让上下文去和接口进行复杂的交互。而上层的调用只需要跟上下文打交道就可以。

策略模式仅仅封装算法，提供新的算法插入到已有系统中，策略模式并不决定在何时使用何种算法。在什么情况下使用什么算法是由客户端决定的。

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


