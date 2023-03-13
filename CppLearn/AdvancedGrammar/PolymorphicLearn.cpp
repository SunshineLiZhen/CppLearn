#include "stdafx.h"
#include "PolymorphicLearn.h"

PolymorphicLearn::PolymorphicLearn()
{
	cout << "************************************STL学习**********************************" << endl;
}

PolymorphicLearn::~PolymorphicLearn()
{
	cout << "************************************STL学习**********************************" << endl;
}

void PolymorphicLearn::opertorExample()
{
	Binomial a(5, 3);
	

	cout << a.geta() << "|" << a.getb() << endl;
	a = -a;// -a相当于a.operator-()
	cout << a.geta() << "|" << a.getb() << endl;

	Binomial b(1, 2);
	a = ++b;
	cout << b.geta() << "|" << b.getb() << endl;
	cout << a.geta() << "|" << a.getb() << endl;

	Binomial c(12, 43);
	a = b++;
	cout << b.geta() << "|" << b.getb() << endl;
	cout << a.geta() << "|" << a.getb() << endl;

	cout << c[0] << endl;
	cout << c[1] << endl;
}


Shape::Shape()
{
	cout << "Shape()" << endl;
}

Shape::~Shape()
{
	cout << "~Shape()" << endl;
}

double Shape::calcArea()
{

	cout << "Shape::calcArea()" << endl;
	return 0;
}

Rectangle::Rectangle(int width, int high):Shape(),m_iWidth(width),m_iHigh(high)
{
	cout << "Rectangle(int ,int)" << endl;
}

Rectangle::~Rectangle()
{
	cout << "~Rectangle()" << endl;
}

double Rectangle::calcArea()
{
	return m_iWidth * m_iHigh;
}

Circle1::Circle1(int r):Shape(),m_iR(r)
{
	cout << "Circle(int)" << endl;
}

Circle1::~Circle1()
{
	cout << "~Circle()" << endl;
}

double Circle1::calcArea()
{
	return 3.14*m_iR*m_iR;
}

//////////////////////////////////////////////////////////////////////
Clothing::Clothing()
{
	cout << "Clothing()" << endl;
}

Jacket::Jacket()
{
	cout << "Jacket()" << endl;
}

float Jacket::getPrice()
{
	return 500.0f;
}

//////////////////////////////////////////////////////////////////////////
Flyble::Flyble()
{
}

Plane::Plane()
{
}

void Plane::takeoff()
{
	cout << "Plane::takeoff()" << endl;
}

void Plane::land()
{
	cout << "Plane::land()" << endl;
}

void Plane::carry()
{
	cout << "Plane::carry()" << endl;
}

Men::Men()
{
}

void Men::talk()
{
	cout << "Men::talk()" << endl;
}

void Men::takeoff()
{
	cout << "Men::takeoff()" << endl;
}

void Men::land()
{
	cout << "Men::land()" << endl;
}
/*
void doSomething(Flyble * obj)
{
	obj->takeoff();
	obj->land();
}
*/
void doSomething(Flyble *obj)
{
	cout << typeid(*obj).name() << endl;
	if (typeid(*obj) == typeid(Men))
	{
		Men *p = dynamic_cast<Men*>(obj);
		p->talk();
	}
	if (typeid(*obj) == typeid(Plane))
	{
		Plane *p = dynamic_cast<Plane*>(obj);
		p->carry();
	}
}
////////////////////////////////////
Binomial::Binomial(int a,int b)
{
	m_iA = a;
	m_iB = b;
}

Binomial::~Binomial()
{
}

int Binomial::geta()
{
	return m_iA;
}

int Binomial::getb()
{
	return m_iB;
}

Binomial Binomial::operator-()
{
	m_iA = -m_iA;
	m_iB = -m_iB;

	return *this;
}

Binomial Binomial::operator++()
{
	m_iA++;
	m_iB++;
	return *this;
}

Binomial Binomial::operator++(int)
{
	Binomial old(*this);
	m_iA++;
	m_iB++;
	return old;
}

Binomial Binomial::operator+(Binomial & bin)
{
	Binomial newB(0, 0);
	newB.m_iA = m_iA + bin.geta();
	newB.m_iB = m_iB + bin.getb();
	
	return newB;
}

int Binomial::operator[](int i)
{
	if (0 == i)
	{
		return m_iA;
	}
	else if(1 == i)
	{
		return m_iB;
	}
	else
	{
		return -1;
	}

}

bool Binomial::operator==(Binomial & bin)
{
	if (this->m_iA == bin.m_iA && this->m_iB == bin.m_iB)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Binomial& Binomial::operator=(Binomial & bin)
{
	this->m_iA = bin.m_iA;
	this->m_iB = bin.m_iB;

	return *this;
}

