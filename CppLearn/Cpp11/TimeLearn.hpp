#pragma once
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

/// <summary>
/// C11ʱ�亯��ѧϰ
/// 1.ʱ��α���
/// 2.ʱ��-ʱ���
/// 3.��ʱ
/// 4.���ʱ���ʽ
/// </summary>
class TimeLearn
{
public:
	void DoTest();

	/// <summary>
	/// ʱ��α���ʹ��ѧϰ
	/// </summary>
	void TimeSlotLearn()
	{
		chrono::hours hour{ 1 };
		chrono::minutes minutes_3{ 3 };
		chrono::seconds second_30{ 30 };
		chrono::milliseconds milliseconds_1000{ 1000 };

		chrono::seconds retVal = minutes_3 - second_30;

		cout << retVal.count() << endl;
	}

	/// <summary>
	/// ʱ������ʹ��ѧϰ
	/// ʱ�ӣ�����ʱ��
	/// 1.ϵͳʱ�ӣ�system_clock:ϵͳʱ�䣬ϵͳʱ����ܱ��޸�
	/// 2.steady_clock:��¼ʱ�䣬���ᱻ�޸ġ���¼�����Ѿ����ŵ�����ʱ�䡣
	/// </summary>
	void TimePointLearn()
	{
		chrono::system_clock::time_point tp1 = chrono::system_clock::now();
		this_thread::sleep_for(chrono::seconds(3));
		chrono::system_clock::time_point tp2 = chrono::system_clock::now();

		std::cout << "time_interval = " << std::chrono::duration_cast<std::chrono::seconds>(tp2 - tp1).count() << "\n";
	}
	

};

