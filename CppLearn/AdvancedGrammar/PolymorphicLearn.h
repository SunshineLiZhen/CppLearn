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
/* 虚函数
定义Shape类、Rectangle类、CirCle类

Shape类
成员函数：构造函数，析构函数，calcArea

Rectangle类
数据成员：m_iWidth,m_iHigh
成员函数：构造函数，析构函数，calcArea

CirCle类
数据成员：m_iR
成员函数：构造函数，析构函数，calcArea
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
/* 纯虚函数-抽象类
定义Clothing类、Jacket类、Trousers类

Clothing衣服类
成员函数：构造函数，getPrice

Jacket上衣类
成员函数：构造函数，析构函数，getPrice
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
/* 接口类
      要求：Flyable类、Plane类、Man类
	  将Flayable定义为接口类，函数：takeoff，land
	  Plane类，成员函数：carry，takeoff，land
	  Men类，成员函数：talk，takeoff，land
	  全局函数：doSomething
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
/* 运算符重载
 * operator overload
*/
/*********************************************************/

// 运算符重载
class Binomial
{
public:
	Binomial(int a, int b);
	~Binomial();
	int geta();
	int getb();

	// 一元运算符重载
	Binomial operator-();
	Binomial operator++();//++a前置++重载
	Binomial operator++(int);//a++后置++重载

	// 二元运算符重载
	Binomial operator+(Binomial &bin);

	// 索引运算符重载
	int operator[](int i);

	// ==关系运算符重载
	bool operator==(Binomial &bin);

	// 赋值运算符重载
	Binomial& operator=(Binomial & bin);
private:
	int m_iA;
	int m_iB;
};