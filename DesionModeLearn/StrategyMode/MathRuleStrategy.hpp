#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// ��ѧ�������
/// </summary>
class IMathOperationStrategy
{
public:
    virtual double  Calculate(double num1,double num2) = 0;

    virtual ~IMathOperationStrategy() {}

};

/// <summary>
/// �ӷ�
/// </summary>
class AddOperation :public IMathOperationStrategy
{
public:
    virtual double Calculate(double num1, double num2) override
    {
        cout << "AppOperation calculate way." << endl;
        return num1 + num2;
    }
};

/// <summary>
/// ����
/// </summary>
class SubstractOperation :public IMathOperationStrategy
{
public:
    virtual double Calculate(double num1, double num2) override
    {
        cout << "SubstractOperation calculate way." << endl;
        return num1 - num2;
    }
};

/// <summary>
/// �˷�
/// </summary>
class MultiplyOperation :public IMathOperationStrategy
{
public:
    virtual double Calculate(double num1, double num2) override
    {
        cout << "MultiplyOperation calculate way." << endl;
        return num1 * num2;
    }
};

/// <summary>
/// ����
/// </summary>
class DivideOperation :public IMathOperationStrategy
{
public:
    virtual double Calculate(double num1, double num2) override
    {
        cout << "DivideOperation calculate way." << endl;
        return num1 /num2;
    }
};


///*** ����չ����



