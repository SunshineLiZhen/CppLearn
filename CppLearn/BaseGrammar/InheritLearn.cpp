#include "stdafx.h"
#include "InheritLearn.h"


#include <iostream>

Worker::Worker(string name, int age) :m_strName(name),m_iAge(age)
{
	cout << "Worker(string name)" << endl;
}

Worker::~Worker()
{
	cout << "~Worker()" << endl;
}

string Worker::getName() const
{
	return m_strName;
}

int Worker::getAge() const
{
	cout << "const getAge()" << endl;
	return m_iAge;
}

Electrician::Electrician(string name, int age,int salary) :Worker(name,age), m_iSalary(salary)
{
	cout << "Elcectician(string name, int age,int salary)" << endl;
}

Electrician::~Electrician()
{
	cout << "~Eclectician()" << endl;
}

void Electrician::printInfo() const
{
	cout << "name:" << m_strName  //父类的protected属性，子类可以访问
		//<< m_iAge  继承之后，父类的私有属性子类不可见，因此子类不可访问
		<< "|salary:" << m_iSalary << endl;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

WorkerMan::WorkerMan(string code):m_strCode(code)
{
	cout << "WorkerMan(string code)" << endl;
}

WorkerMan::~WorkerMan()
{
	cout << "~WorkerMan()" << endl;
}

string WorkerMan::getCode()
{
	return m_strCode;
}

Farmer::Farmer(int age):m_iAge(age)
{
	cout << "Farmer(int age)" << endl;
}

Farmer::~Farmer()
{
	cout << "~Farmer()" << endl;
}

int Farmer::getAge()
{
	return m_iAge;
}

Migrantworker::Migrantworker(string code, int age, int salary):WorkerMan(code),Farmer(age)
{
	cout << "Migrantworker(string code, int age, int salary)" << endl;
	m_iSalary = salary;
}

Migrantworker::~Migrantworker()
{
	cout << "~Migrantworker()" << endl;
}

int Migrantworker::getSalary()
{
	return m_iSalary;
}

Person::Person(string name):m_strName(name)
{
	cout << "Person()" << endl;
}

Person::~Person()
{
	cout << "~Person()" << endl;
}

string Person::getName() const
{
	return m_strName;
}

Delicacy::Delicacy(string name, string code):Person(name),m_strCode(code)
{
	cout << "Delicacy()" << endl;
}

Delicacy::~Delicacy()
{
	cout << "~Delicacy()" << endl;
}

string Delicacy::getCode() const
{
	return m_strCode;
}

CookMan::CookMan(string name,int age ):Person(name),m_iAge(age)
{
	cout << "CookMan()" << endl;
}

CookMan::~CookMan()
{
	cout << "~CookMan()" << endl;
}

int CookMan::getAge() const
{
	return m_iAge;
}

DelicacyFoodCooker::DelicacyFoodCooker(string name, string code, int age, int salary):Delicacy(name,code),CookMan(name,age),Person(name),m_iSalary(salary)
{
	cout << "DelicacyFoodCooker()" << endl;
}



DelicacyFoodCooker::~DelicacyFoodCooker()
{
	cout << "~DelicacyFoodCooker()" << endl;
}

int DelicacyFoodCooker::getSalary() const
{
	return m_iSalary;
}
