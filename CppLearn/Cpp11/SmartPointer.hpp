#pragma once
#include <chrono>
#include <iostream>
using namespace std;

class CObjB;
class CObjA
{
public:
	CObjA() { cout << "this is CObjA Construct!" << endl; };
	~CObjA() { cout << "this is CObjA Destory!" << endl; }
public:
	shared_ptr< CObjB> m_cobjB;
};

class CObjB
{
public:
	CObjB() { cout << "this is CObjB Construct!" << endl; };
	~CObjB() { cout << "this is CObjB Destory!" << endl; }
public:
	shared_ptr< CObjA> m_cobjA;
};



class CObjWB;
class CObjWA
{
public:
	CObjWA() { cout << "this is CObjA Construct!" << endl; };
	~CObjWA() { cout << "this is CObjA Destory!" << endl; }
public:
	weak_ptr<CObjWB> m_cobjB;
};

class CObjWB
{
public:
	CObjWB() { cout << "this is CObjB Construct!" << endl; };
	~CObjWB() { cout << "this is CObjB Destory!" << endl; }
public:
	weak_ptr< CObjWA> m_cobjA;
};

class Car
{
public:
	Car()
	{
		cout << "car 构造函数" << endl;
	}
	~Car()
	{
		cout << "car 析构函数" << endl;
	}
};
/// <summary>
/// 智能指针学习
/// shared_ptr,unique_ptr,weak_ptr
/// </summary>
class SmartPointerLearn
{
public:
	// 循环引用测试
	auto test()
	{
		shared_ptr< CObjA> ca = make_shared< CObjA>();
		shared_ptr< CObjB> cb = make_shared< CObjB>();

		ca->m_cobjB = cb;

		cb->m_cobjA = ca;

		cout << cb.use_count() << endl;
		cout << ca.use_count() << endl;
		return 1;
	}

	auto test2()
	{
		shared_ptr< CObjWA> ca = make_shared< CObjWA>();
		shared_ptr< CObjWB> cb = make_shared< CObjWB>();

		ca->m_cobjB = cb;

		cb->m_cobjA = ca;

		cout << cb.use_count() << endl;
		cout << ca.use_count() << endl;
	}

	/// <summary>
	/// 智能指针使用
	/// </summary>
	void UseSharedPtr()
	{
		// 初始化方法
		// 1
		shared_ptr<int> p1 = make_shared<int>(1);

		// 2 赋值
		shared_ptr<int> p2 = p1;

		cout << p1.use_count() << endl; // 2
		cout << p2.use_count() << endl; // 2

		// 3 拷贝构造函数
		shared_ptr<int>p3(p2);
		cout << p3.use_count() << endl; // 3

	}

	/// <summary>
	/// unique指针使用
	/// </summary>
	void UseUniquePtr()
	{
		unique_ptr<int> p1 = make_unique<int>(1);

		//unique_ptr<int> p2 = p1; // 编译错误，不允许赋值和复制

		unique_ptr<int> p3 = move(p1);// 转移所有权, 现在那块内存归p3所有, p1成为无效的指针.

		if (p1 == nullptr)
		{
			cout << "p1 is null ptr" << endl;
		}
	}

	void WeakPtrLearn()
	{
		Car c;
		//Car* pc = &c;
		Car* pc = new Car();
		shared_ptr<Car> spc(pc);

		Car* pCar = new Car();
		shared_ptr<Car> sp1(pCar);
		shared_ptr<Car> sp2(pCar);

		cout << sp1.use_count() << endl; // 1
		cout << sp2.use_count() << endl; // 1
		cout << "====" << endl; 

		weak_ptr<Car> wp = spc;

	}
};






