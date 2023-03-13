#pragma once
#include <chrono>

/// <summary>
/// 左值引用和右值引用都是为了提高效率
/// </summary>
class RValueLearn
{
public:
	
	int add(int a, int b)
	{
		int res;
		res = a + b;

		return res;
	}


	void situation1()
	{
		int a = 3;
		int b = 4;
		int c;

		// 此操作会产生4次复制
		// 2次：a,b的值复制给add函数的实参。
		// 1次：add函数中res的值复制给返回值x(临时对象）。因为res是栈内存，add调用结束就会销毁
		// 1次：x复制给c
		c = add(a, b);
	}

	/// 解决方法1
	void add(int* a, int* b, int* result)
	{
		*result = *a + *b;
	}

	/// <summary>
	/// 传指针的开销几乎可以忽略不计，所以整体效率终于提上去了.
	/// 但像 add(&a, &b, &result) 的书写代码的形式，以及通过指针访问内部变量->的符号实在不太优雅。
	/// 而且关键是，编程的思维方式变了，我们时刻想着要传指针，要提前准备好空变量（result）让函数内操作它，
	/// 这种函数内部操作外部资源的扭曲思想，确实不是一个好法子。
	/// </summary>
	void solveWay1()
	{
		int a = 3;
		int b = 4;
		int c;
		add(&a, &b, &c);
	}
	
	
	/// 解决方法2
	void add(int& ra, int& rb, int& result)
	{
		result = ra + rb;
	}

	/// <summary>
	/// 引用定义的变量 ra 本质上是一个指针（编译器在底层就是这么干的），
	/// 但它抛弃了指针那一套操作符号（* 和 ->），和对象的使用完全没两样，代码上直观多了
	/// </summary>
	void solveWay2()
	{
		int a = 3;
		int b = 4;
		int c;
		add(a,b,c);
	}


	/// <summary>
	/// 对于 C++98 的引用，我们用得更多的是函数传入参数，以避免临时对象的产生和深度拷贝开销；
	/// 而在函数传出（返回值）上，只能返回成员对象的引用，应用面很窄。
	/// </summary>


	
	/// 右值有哪些：
	// 1.字面常量
	// 2.临时变量
	//   a)函数返回值
	//   b)表达式结果
	//   c)变量类型隐式转换
	int&& test1()
	{
		int&& x = 10;
		x = 100;
		int y = x;
		int a = 10;
		return std::move(a);
	}
};


