#pragma once
#include <vector>

class DesignModeLearn
{
public:
	DesignModeLearn();
	~DesignModeLearn();

	void observerExample();

};

/*****************************************************************************/
/*  单例模式 ~ 线程不安全
 *  单例大约有两种实现方法：懒汉与饿汉。
    懒汉：故名思义，不到万不得已就不会去实例化类，也就是说在第一次用到类实例的时候才会去实例化；
    饿汉：饿了肯定要饥不择食。所以在单例类定义的时候就进行实例化。
　　特点与选择：
    由于要进行线程同步，所以在访问量比较大，或者可能访问的线程比较多时，采用饿汉实现，可以实现更好的性能。这是以空间换时间。
    在访问量较小时，采用懒汉实现。这是以时间换空间。
*/
/*****************************************************************************/
class Singleton
{
public:
	//对外接口
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton();//防止外部调用构造函数创建对象
	Singleton(Singleton const & singleton);//阻止拷贝创建对象
	Singleton& operator=(Singleton const &singleton) { Singleton sing; return sing; };//阻止赋值对象
};
/*
class Singleton1
{
public:
	static Singleton1* instance();
protected:
	Singleton1() {};
	Singleton1(Singleton1 const & singleton) {};
	Singleton1& operator=(Singleton1 const & singleton) { Singleton1 sing; return sing; };

private:
	static Singleton1* p;
};

Singleton1* Singleton1::p = NULL;
Singleton1* Singleton1::instance()
{
	if (NULL == p)
	{
		p =  new Singleton1();
		return p;
	}
}*/
/*****************************************************************************/
/*  观察者模式
*/
/*****************************************************************************/

//data是根据实际需求定义的数据结构
//传输的数据结构
class WeatherData
{
public:
	float m_fTemperature;//温度
	float m_fPressure;//压力
	float m_fHumidity;//湿度
public:
	WeatherData();
	WeatherData(float temperature, float pressure, float humidity);
	~WeatherData();
};

class Observer;
// 主题
class Subject
{
public:
	virtual void addObserver(Observer *ob);
	virtual void removeObserver(Observer *ob);
	virtual void notifyObserver();
	virtual void notifyObserver(WeatherData data);
public:
	Subject();
	virtual ~Subject();
protected:
	std::vector<Observer*> m_vObserverList;
};

// 观察者
class Observer
{
public:
	virtual void notify() = 0;
	virtual void notify(WeatherData data) = 0;
public:
	Observer();
	virtual ~Observer();
protected:
};

class WeatherSubject : public Subject
{
public:
	float getTemperature();
	float getPressure();
	float getHumidity();
	void setData(float temperature, float pressure, float humidity);
	void dataChanged();
public:
	WeatherSubject();
	~WeatherSubject();
protected:
	float m_fTemperature;//温度
	float m_fPressure;//压力
	float m_fHumidity;//湿度
};

class WeatherObserver :public Observer
{
public:
	void notify();
	void notify(WeatherData data);
	void display();
public:
	WeatherObserver();
	~WeatherObserver();
private:
	WeatherData m_cWeather;
};