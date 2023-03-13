#pragma once
#include <iostream>
#include "ShangHaiWeatherObserver.hpp"
#include "BeiJingWeatherObserver.hpp"
#include "WeatherSubject.hpp"

using namespace std;

/// <summary>
/// ʹ����
/// </summary>
class ObserverModeUser
{
private:

public:
	void Test()
	{
		// �����۲���
		auto ob1 = make_shared<ShanghaiWeatherObserver>();
		auto ob2 = make_shared<BeiJingWeatherObserver>();

		// ��������
		auto sub = WeatherSubject();

		// ����
		sub.Attach(ob1);
		sub.Attach(ob2);

		// ֪ͨ�۲���
		sub.Notify(100);
	}
};




