#pragma once
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

/// <summary>
/// C11时间函数学习
/// 1.时间段变量
/// 2.时钟-时间点
/// 3.计时
/// 4.输出时间格式
/// </summary>
class TimeLearn
{
public:
	void DoTest();

	/// <summary>
	/// 时间段变量使用学习
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
	/// 时间点变量使用学习
	/// 时钟：两种时钟
	/// 1.系统时钟，system_clock:系统时间，系统时间可能被修改
	/// 2.steady_clock:记录时间，不会被修改。记录的是已经流逝的真正时间。
	/// </summary>
	void TimePointLearn()
	{
		chrono::system_clock::time_point tp1 = chrono::system_clock::now();
		this_thread::sleep_for(chrono::seconds(3));
		chrono::system_clock::time_point tp2 = chrono::system_clock::now();

		std::cout << "time_interval = " << std::chrono::duration_cast<std::chrono::seconds>(tp2 - tp1).count() << "\n";
	}
	

};

