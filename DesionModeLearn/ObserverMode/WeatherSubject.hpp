#pragma once
#include <iostream>
#include "IWeatherSubject.hpp"
#include <list>

using namespace std;

/// <summary>
/// ��������
/// </summary>
class WeatherSubject:public IWeatherSubject
{
private:
    list<shared_ptr<IWeatherObserver>> m_observerList;

public:
    /// <summary>
    /// ��ӹ۲���
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
    /// ɾ���۲���
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
    /// ֪ͨ�۲���
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




