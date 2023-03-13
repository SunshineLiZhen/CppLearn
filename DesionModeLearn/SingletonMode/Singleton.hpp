//#pragma once
//#include <iostream>
//#include<mutex>
//
//using namespace std;
//
///// <summary>
///// ����ģʽ
///// https://blog.csdn.net/zyhse/article/details/105336468
///// </summary>
//class Singleton
//{
//private:
//	Singleton() = default;
//	~Singleton() = default;
//
//	Singleton(const Singleton& other) = delete;//��ֹcopy
//	Singleton& operator =(const Singleton&) = delete;//��ֹ��ֵ
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
///// �̲߳���ȫ�汾
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
///// �̰߳�ȫ�汾1
///// �ӻ�����
///// ȱ�㣺������ʱ�����Ĵ��ڸ߲���������������
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
///// �̰߳�ȫ�汾2
///// ˫��������������ڴ��дreorder����ȫ
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
////C++ 11�汾֮��Ŀ�ƽ̨ʵ�� (volatile)
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