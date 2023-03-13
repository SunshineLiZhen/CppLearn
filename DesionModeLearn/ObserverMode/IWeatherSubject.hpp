#pragma once
#include <iostream>
#include "IWeatherObserver.hpp"

using namespace std;

/// <summary>
/// 天气主题
/// </summary>
class IWeatherSubject
{
public:
    virtual bool  Attach(shared_ptr<IWeatherObserver> ob) = 0;

    virtual bool  Detach(shared_ptr<IWeatherObserver> ob) = 0;

    virtual void Notify(float temper) = 0;

    virtual ~IWeatherSubject() {}

};




