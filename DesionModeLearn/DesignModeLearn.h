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
/*  ����ģʽ ~ �̲߳���ȫ
 *  ������Լ������ʵ�ַ����������������
    ����������˼�壬�����򲻵��ѾͲ���ȥʵ�����࣬Ҳ����˵�ڵ�һ���õ���ʵ����ʱ��Ż�ȥʵ������
    ���������˿϶�Ҫ������ʳ�������ڵ����ඨ���ʱ��ͽ���ʵ������
�����ص���ѡ��
    ����Ҫ�����߳�ͬ���������ڷ������Ƚϴ󣬻��߿��ܷ��ʵ��̱߳Ƚ϶�ʱ�����ö���ʵ�֣�����ʵ�ָ��õ����ܡ������Կռ任ʱ�䡣
    �ڷ�������Сʱ����������ʵ�֡�������ʱ�任�ռ䡣
*/
/*****************************************************************************/
class Singleton
{
public:
	//����ӿ�
	static Singleton& getInstance()
	{
		static Singleton instance;
		return instance;
	}

private:
	Singleton();//��ֹ�ⲿ���ù��캯����������
	Singleton(Singleton const & singleton);//��ֹ������������
	Singleton& operator=(Singleton const &singleton) { Singleton sing; return sing; };//��ֹ��ֵ����
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
/*  �۲���ģʽ
*/
/*****************************************************************************/

//data�Ǹ���ʵ������������ݽṹ
//��������ݽṹ
class WeatherData
{
public:
	float m_fTemperature;//�¶�
	float m_fPressure;//ѹ��
	float m_fHumidity;//ʪ��
public:
	WeatherData();
	WeatherData(float temperature, float pressure, float humidity);
	~WeatherData();
};

class Observer;
// ����
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

// �۲���
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
	float m_fTemperature;//�¶�
	float m_fPressure;//ѹ��
	float m_fHumidity;//ʪ��
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