#pragma once
#include <iostream>
#include "IWeatherObserver.hpp"

using namespace std;

/// <summary>
/// 上海天气观察者
/// </summary>
class ShanghaiWeatherObserver:public IWeatherObserver
{
public:
    virtual void  Update(float temper) override
    {
        cout << "shang hai: " << "update temper:" << temper << endl;
    }

    virtual ~ShanghaiWeatherObserver() {}
};






