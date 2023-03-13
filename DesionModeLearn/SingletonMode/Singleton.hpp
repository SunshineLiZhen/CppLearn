//#pragma once
//#include <iostream>
//#include<mutex>
//
//using namespace std;
//
///// <summary>
///// 单例模式
///// https://blog.csdn.net/zyhse/article/details/105336468
///// </summary>
//class Singleton
//{
//private:
//	Singleton() = default;
//	~Singleton() = default;
//
//	Singleton(const Singleton& other) = delete;//阻止copy
//	Singleton& operator =(const Singleton&) = delete;//阻止赋值
//
//	static shared_ptr<Singleton> m_instance;
//	static mutex m_mutex;
//
//public:
//	static shared_ptr<Singleton> GetInstance();
//}
//
//
//std::once_flag Singleton::m_flag;
//
///// <summary>
///// 线程不安全版本
///// </summary>
///// <returns></returns>
//shared_ptr<Singleton>Singleton::Getinstance()
//{
//	if (m_instance == nullptr)
//	{
//		m_instance = make_shared< Singleton>();
//	}
//
//	return m_instance;
//}
//
///// <summary>
///// 线程安全版本1
///// 加互斥锁
///// 缺点：互斥锁时间消耗大，在高并发场景，更明显
///// </summary>
///// <returns></returns>
//shared_ptr<Singleton>Singleton::Getinstance()
//{
//	unique_lock<mutex> lg(m_mutex);
//	if (m_instance == nullptr)
//	{
//		m_instance = make_shared< Singleton>();
//	}
//
//	return m_instance;
//}
//
//
///// <summary>
///// 线程安全版本2
///// 双检查锁，但由于内存读写reorder不安全
///// </summary>
///// <returns></returns>
//shared_ptr<Singleton>Singleton::Getinstance()
//{
//	if (m_instance == nullptr)
//	{
//		unique_lock<mutex> lg(m_mutex);
//		if (m_instance == nullptr)
//		{
//			m_instance = make_shared< Singleton>();
//		}
//	}
//
//	return m_instance;
//}
//
////C++ 11版本之后的跨平台实现 (volatile)
//shared_ptr<Singleton> Singleton::Getinstance()
//{
//	std::call_once(m_flag, 
//		[&]() 
//		{
//		m_instance = make_shared< Singleton>();
//		}
//	);
//	return m_instance;
//}