#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// 数学运算策略
/// </summary>
class IMathOperationStrategy
{
public:
    virtual double  Calculate(double num1,double num2) = 0;

    virtual ~IMathOperationStrategy() {}

};

/// <summary>
/// 加法
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
/// 减法
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
/// 乘法
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
/// 除法
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


///*** 对扩展开放



