#pragma once

class InheritGrammer11
{
public:
};


/// <summary>
/////////////////////////////////////////////////////////////////////////////////////// final�ؼ���ѧϰ
/// </summary>
class Car final
{
public:
	void GetName() {};

};

// ������̳�final�࣬�﷨����
//class Bus :Car
//{
//
//};

class Animal
{
public:
	virtual void GetName() final{}
};

class Dog :public Animal
{
public:
	// ��������дfinal�麯�����﷨����
	//virtual void GetName() {}
};


/// <summary>
/// ////////////////////////////////////////////////////////////////////////////////overrideѧϰ  
/// ����������麯���Ƿ���д�˻���ĳ���麯�������û����д���뱨��
/// </summary>
class Student
{
public:
	virtual void GetName() {}
};

class ZhangStudent:public Student
{
public:
	virtual void GetName() override {}
};