#pragma once
#include <iostream>
#include "IMessagerExpand.hpp"

using namespace std;

//ƽ̨ʵ�� n
class PCMessagerImp : public IMessagerExpand {
public:

    virtual void PlaySound()  override
    {
        //**********
    }
    virtual void DrawShape()  override 
    {
        //**********
    }
    virtual void WriteText()  override 
    {
        //**********
    }
    virtual void Connect()  override 
    {
        //**********
    }
};

class MobileMessagerImp : public IMessagerExpand {
public:

    virtual void PlaySound()  override 
    {
        //==========
    }
    virtual void DrawShape() override
    {
        //==========
    }
    virtual void WriteText() override
    {
        //==========
    }
    virtual void Connect()  override 
    {
        //==========
    }
};

