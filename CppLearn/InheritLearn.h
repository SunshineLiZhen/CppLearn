#pragma once
#include <string>
using namespace std;
/*********************************************************/
/* �̳е�ѧϰ
   �̳з�ʽ
   ���ؼ̳�
   ��̳�
*/
/*********************************************************/



/*********************************************************/
/* ���м̳�
����Worker���Electrician��
WorkerΪ���࣬Electrician��Ϊ����
Worker��
���ݳ�Ա��m_strName,m_iAge
��Ա���������캯��������������getName

Electrician��
���ݳ�Ա��m_iSalary
��Ա���������캯��������������printInfo
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
	int m_iAge;//����
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
/* ��̳�
   ����WorkerMan�ࡢFarmer�ࡢMigrantWorker��

	Worker��
		���ݳ�Ա��m_strCode
		��Ա���������캯��������������getCode

	Farmer��
		���ݳ�Ա��m_iAge
		��Ա���������캯��������������getAge
	
	MigrantWorkerũ����
		���ݳ�Ա��m_iSalary
		��Ա���������캯��������������getSalary
*/
/*********************************************************/


class WorkerMan
{
public:
	WorkerMan(string code);
	~WorkerMan();
	string getCode();
protected:
	string m_strCode;//����
};

class Farmer
{
public:
	Farmer(int age);
	~Farmer();
	int getAge();
protected:
	int m_iAge;//����
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
/* ���μ̳�~��̳�
����Person�ࡢDelicacy��ʳ���ࡢCookMan��ʦ�࣬DelicacyFoodCooker����ζ���ȵĳ�ʦ��
	Delicacy��̳�Person�� ��CookMan��̳�Person��
	DelicacyFoodCooker��̳�Delicacy�࣬CookMan��

	Person��
		���ݳ�Ա��m_strName
		��Ա���������캯��������������getName

	Delicacy��
		���ݳ�Ա��m_iCode
		��Ա���������캯��������������getCode

	CookMan��
		���ݳ�Ա��m_iAge
		��Ա���������캯��������������getAge

	DelicacyFoodCooker�� 
		���ݳ�Ա��m_iSalary
		��Ա���������캯��������������getSalary
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