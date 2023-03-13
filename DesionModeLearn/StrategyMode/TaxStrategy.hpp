#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// ˰�ʲ���
/// </summary>
class ITaxStrategy
{
public:
    virtual double  Calculate(double price) = 0;

    virtual string GetSupportType() = 0;

    virtual ~ITaxStrategy() {}

};

class USTax :public ITaxStrategy
{
public:
    virtual double Calculate(double price) override
    {
        cout << "USTax calculate way." << endl;
    }

    virtual string GetSupportType() override
    {
        return "USTax";
    }
};

class CNTax :public ITaxStrategy
{
public:
    virtual double Calculate(double price) override
    {
        cout << "CNTax calculate way." << endl;
    }

    virtual string GetSupportType() override
    {
        return "CNTax";
    }
};

///*** ����չ����



