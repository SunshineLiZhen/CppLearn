#pragma once
#include <iostream>
#include "ShangHaiWeatherObserver.hpp"
#include "BeiJingWeatherObserver.hpp"
#include "WeatherSubject.hpp"

using namespace std;

/// <summary>
/// 使用者
/// </summary>
class ObserverModeUser
{
private:

public:
	void Test()
	{
		// 创建观察者
		auto ob1 = make_shared<ShanghaiWeatherObserver>();
		auto ob2 = make_shared<BeiJingWeatherObserver>();

		// 创建主题
		auto sub = WeatherSubject();

		// 关联
		sub.Attach(ob1);
		sub.Attach(ob2);

		// 通知观察者
		sub.Notify(100);
	}
};




