#pragma once
#include <iostream>

using namespace std;
class PolymorphicLearn
{
public:
	PolymorphicLearn();
	~PolymorphicLearn();
	void opertorExample();
};
/*********************************************************/
/* �麯��
����Shape�ࡢRectangle�ࡢCirCle��

Shape��
��Ա���������캯��������������calcArea

Rectangle��
���ݳ�Ա��m_iWidth,m_iHigh
��Ա���������캯��������������calcArea

CirCle��
���ݳ�Ա��m_iR
��Ա���������캯��������������calcArea
*/
/*********************************************************/

class Shape
{
public:
	Shape();
	~Shape();
	virtual double calcArea();
};

class Rectangle:public Shape
{
public:
	Rectangle(int width, int high);
	~Rectangle();
	virtual double calcArea();
protected:
	int m_iWidth;
	int m_iHigh;
};

class Circle1 :public Shape
{
public:
	Circle1(int r);
	~Circle1();
	virtual double calcArea();
protected:
	int m_iR;
};


/*********************************************************/
/* ���麯��-������
����Clothing�ࡢJacket�ࡢTrousers��

Clothing�·���
��Ա���������캯����getPrice

Jacket������
��Ա���������캯��������������getPrice
*/
/*********************************************************/
class Clothing
{
public:
	Clothing();
	virtual float getPrice() = 0;
};

class Jacket:public Clothing
{
public:
	Jacket();
	virtual float getPrice();
};


/*********************************************************/
/* �ӿ���
      Ҫ��Flyable�ࡢPlane�ࡢMan��
	  ��Flayable����Ϊ�ӿ��࣬������takeoff��land
	  Plane�࣬��Ա������carry��takeoff��land
	  Men�࣬��Ա������talk��takeoff��land
	  ȫ�ֺ�����doSomething
*/
/*********************************************************/
class Flyble
{
public:
	Flyble();
	virtual void takeoff() = 0;
	virtual void land() = 0;
};

class Plane:public Flyble
{
public:
	Plane();
	virtual void takeoff();
	virtual void land();
	void carry();
};

class Men :public Flyble
{
public:
	Men();
	virtual void takeoff();
	virtual void land();
	void talk();
};

void doSomething(Flyble *obj);

/*********************************************************/
/* ���������
 * operator overload
*/
/*********************************************************/

// ���������
class Binomial
{
public:
	Binomial(int a, int b);
	~Binomial();
	int geta();
	int getb();

	// һԪ���������
	Binomial operator-();
	Binomial operator++();//++aǰ��++����
	Binomial operator++(int);//a++����++����

	// ��Ԫ���������
	Binomial operator+(Binomial &bin);

	// �������������
	int operator[](int i);

	// ==��ϵ���������
	bool operator==(Binomial &bin);

	// ��ֵ���������
	Binomial& operator=(Binomial & bin);
private:
	int m_iA;
	int m_iB;
};