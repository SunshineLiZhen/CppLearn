#pragma once

#include <iostream>
#include <chrono> // ͷ�ļ�

class TimeExpandCount
{
public:
	TimeExpandCount();

	/// <summary>
	/// ��ʼ��ʱ
	/// </summary>
	void StartCount();

	/// <summary>
	/// ������ʱ�������ؾ���������
	/// </summary>
	/// <returns></returns>
	int StopCount();

private:
	std::chrono::steady_clock::time_point m_startTime;

};

