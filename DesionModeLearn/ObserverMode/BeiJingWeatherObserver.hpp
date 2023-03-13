#pragma once
#include <iostream>
#include "IWeatherObserver.hpp"


using namespace std;

/// <summary>
/// 北京天气观察者
/// </summary>
class BeiJingWeatherObserver:public IWeatherObserver
{
public:
    virtual void  Update(float temper) override
    {
        cout << "Bei jing: "<< "update temper:" << temper << endl;
    }

    virtual ~BeiJingWeatherObserver() {}
};






