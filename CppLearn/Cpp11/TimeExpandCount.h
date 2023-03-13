#pragma once

#include <iostream>
#include <chrono> // 头文件

class TimeExpandCount
{
public:
	TimeExpandCount();

	/// <summary>
	/// 开始计时
	/// </summary>
	void StartCount();

	/// <summary>
	/// 结束计时，并返回经过的秒数
	/// </summary>
	/// <returns></returns>
	int StopCount();

private:
	std::chrono::steady_clock::time_point m_startTime;

};

