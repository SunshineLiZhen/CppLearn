#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// ���������۲���
/// </summary>
class IWeatherObserver
{
public:
    virtual void  Update(float temper) = 0;

    virtual ~IWeatherObserver() {}
};






