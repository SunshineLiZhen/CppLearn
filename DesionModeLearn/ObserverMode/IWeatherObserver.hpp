#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// 抽象天气观察者
/// </summary>
class IWeatherObserver
{
public:
    virtual void  Update(float temper) = 0;

    virtual ~IWeatherObserver() {}
};






