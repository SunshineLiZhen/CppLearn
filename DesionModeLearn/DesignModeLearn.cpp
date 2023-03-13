#include "stdafx.h"
#include "DesignModeLearn.h"

using namespace std;

DesignModeLearn::DesignModeLearn()
{
	std::cout << "************************************设计模式学习**********************************" << endl;
}


DesignModeLearn::~DesignModeLearn()
{
	std::cout << "************************************设计模式学习**********************************" << endl;
}

void DesignModeLearn::observerExample()
{
	Subject *pSub = new WeatherSubject();
	Observer *pOb1 = new WeatherObserver();
	Observer *pOb2 = new WeatherObserver();
	Observer *pOb3 = new WeatherObserver();
	Observer *pOb4 = new WeatherObserver();

	pSub->addObserver(pOb1);
	pSub->addObserver(pOb2);
	pSub->addObserver(pOb3);
	pSub->addObserver(pOb4);

	WeatherData data(12.0f, 100.0f, 60.0f);
	pSub->notifyObserver(data);

	WeatherObserver *pW = dynamic_cast<WeatherObserver*>(pOb1);
	pW->display();
}


void Subject::addObserver(Observer * ob)
{
	// 检查是否有重复
	auto it = std::find(m_vObserverList.begin(), m_vObserverList.end(), ob);
	if (it == m_vObserverList.end())
	{
		m_vObserverList.push_back(ob);
	}
}

void Subject::removeObserver(Observer * ob)
{
	for (auto it = m_vObserverList.begin(); it != m_vObserverList.end(); it++)
	{
		if (ob == *it)
		{
			delete *it;//释放内存
			(*it) = NULL;
			m_vObserverList.erase(it);//删除元素
			break;
		}
	}
}

void Subject::notifyObserver()
{
	for (auto it = m_vObserverList.begin(); it != m_vObserverList.end(); it++)
	{
		(*it)->notify();
	}
}

void Subject::notifyObserver(WeatherData data)
{
	for (auto it = m_vObserverList.begin(); it != m_vObserverList.end(); it++)
	{
		(*it)->notify(data);
	}
}

Subject::Subject()
{
}

Subject::~Subject()
{
	for (auto it = m_vObserverList.begin(); it != m_vObserverList.end();)
	{
		delete *it;
		*it = NULL;
	}
}

Observer::Observer()
{
}

Observer::~Observer()
{
}

WeatherData::WeatherData()
{
}

WeatherData::WeatherData(float temperature, float pressure, float humidity)
{
	m_fTemperature = temperature;
	m_fPressure = pressure;
	m_fHumidity = humidity;
}

WeatherData::~WeatherData()
{
}

float WeatherSubject::getTemperature()
{
	return m_fTemperature;
}

float WeatherSubject::getPressure()
{
	return m_fPressure;
}

float WeatherSubject::getHumidity()
{
	return m_fHumidity;
}

void WeatherSubject::setData(float temperature, float pressure, float humidity)
{
	m_fTemperature = temperature;
	m_fPressure = pressure;
	m_fHumidity = humidity;
}

void WeatherSubject::dataChanged()
{
	WeatherData data(m_fTemperature, m_fPressure, m_fHumidity);
	notifyObserver(data);
}

WeatherSubject::WeatherSubject():Subject()
{
}

WeatherSubject::~WeatherSubject()
{
}

void WeatherObserver::notify()
{
}

void WeatherObserver::notify(WeatherData data)
{
	m_cWeather.m_fHumidity = data.m_fHumidity;
	m_cWeather.m_fPressure = data.m_fPressure;
	m_cWeather.m_fTemperature = data.m_fTemperature;
}

void WeatherObserver::display()
{
	std::cout << "天气预报" << std::endl;
	std::cout << "温度：" << m_cWeather.m_fTemperature << std::endl;
	std::cout << "湿度：" << m_cWeather.m_fHumidity << std::endl;
	std::cout << "气压：" << m_cWeather.m_fPressure << std::endl;
}

WeatherObserver::WeatherObserver():Observer()
{
}

WeatherObserver::~WeatherObserver()
{
}

