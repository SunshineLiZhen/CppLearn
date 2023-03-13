#pragma once
#include <iostream>
#include "IWeatherSubject.hpp"
#include <list>

using namespace std;

/// <summary>
/// 天气主题
/// </summary>
class WeatherSubject:public IWeatherSubject
{
private:
    list<shared_ptr<IWeatherObserver>> m_observerList;

public:
    /// <summary>
    /// 添加观察者
    /// </summary>
    /// <param name="ob"></param>
    /// <returns></returns>
    virtual bool  Attach(shared_ptr<IWeatherObserver> ob) override
    {
        if (ob != nullptr)
        {
            m_observerList.push_back(ob);
        }
    }

    /// <summary>
    /// 删除观察者
    /// </summary>
    /// <param name="ob"></param>
    /// <returns></returns>
    virtual bool  Detach(shared_ptr<IWeatherObserver> ob) override
    {
        if (ob != nullptr)
        {
            m_observerList.remove(ob);
        }
    }


    /// <summary>
    /// 通知观察者
    /// </summary>
    /// <param name="temper"></param>
    virtual void Notify(float temper) override
    {
        for (auto it : m_observerList)
        {
            it->Update(temper);
        }
    }

};




