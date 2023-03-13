#pragma once
#include <string>
using namespace std;
/*********************************************************/
/* 继承的学习
   继承方式
   多重继承
   多继承
*/
/*********************************************************/



/*********************************************************/
/* 公有继承
定义Worker类和Electrician类
Worker为父类，Electrician类为子类
Worker类
数据成员：m_strName,m_iAge
成员函数：构造函数，析构函数，getName

Electrician类
数据成员：m_iSalary
成员函数：构造函数，析构函数，printInfo
*/
/*********************************************************/
class Worker
{
public:
	Worker(string name,int age);
	~Worker();
	string getName() const;
	int getAge() const;
protected:
	string m_strName;
private:
	int m_iAge;//年龄
};

class Electrician :public Worker
{
public:
	Electrician(string name, int age, int salary);
	~Electrician();
	void printInfo() const;
protected:
	const int m_iSalary;
};


/*********************************************************/
/* 多继承
   定义WorkerMan类、Farmer类、MigrantWorker类

	Worker类
		数据成员：m_strCode
		成员函数：构造函数，析构函数，getCode

	Farmer类
		数据成员：m_iAge
		成员函数：构造函数，析构函数，getAge
	
	MigrantWorker农民工类
		数据成员：m_iSalary
		成员函数：构造函数，析构函数，getSalary
*/
/*********************************************************/


class WorkerMan
{
public:
	WorkerMan(string code);
	~WorkerMan();
	string getCode();
protected:
	string m_strCode;//工号
};

class Farmer
{
public:
	Farmer(int age);
	~Farmer();
	int getAge();
protected:
	int m_iAge;//工号
};

class Migrantworker:public WorkerMan,public Farmer
{
public:
	Migrantworker(string code, int age, int salary);
	~Migrantworker();
	int getSalary();
private:
	int m_iSalary;
};

/*********************************************************/
/* 菱形继承~虚继承
定义Person类、Delicacy美食家类、CookMan厨师类，DelicacyFoodCooker做美味佳肴的厨师类
	Delicacy类继承Person类 ，CookMan类继承Person类
	DelicacyFoodCooker类继承Delicacy类，CookMan类

	Person类
		数据成员：m_strName
		成员函数：构造函数，析构函数，getName

	Delicacy类
		数据成员：m_iCode
		成员函数：构造函数，析构函数，getCode

	CookMan类
		数据成员：m_iAge
		成员函数：构造函数，析构函数，getAge

	DelicacyFoodCooker类 
		数据成员：m_iSalary
		成员函数：构造函数，析构函数，getSalary
*/
/*********************************************************/
class Person
{
public:
	Person(string name);
	~Person();
	string getName() const;
protected:
	string m_strName;
};

class Delicacy:virtual public Person
{
public:
	Delicacy(string name,string code);
	~Delicacy();
	string getCode() const;
protected:
	string m_strCode;
};

class CookMan :virtual public Person
{
public:
	CookMan(string name,int age);
	~CookMan();
	int getAge() const;
protected:
	int m_iAge;
};

class DelicacyFoodCooker:public Delicacy,public CookMan
{
public:
	DelicacyFoodCooker(string name, string code, int age, int salary);
	~DelicacyFoodCooker();
	int getSalary() const;
protected:
	int m_iSalary;
};