#pragma once
#include <iostream>
#include "IMessager.hpp"

using namespace std;

//业务抽象 m

//类的数目：1+n+m

class MessagerLite :public IMessager {


public:

    virtual void Login(string username, string password) override
    {

        m_messagerExp->Connect();
        //........
    }
    virtual void SendMessage(string message)  override 
    {

        m_messagerExp->WriteText();
        //........
    }
    virtual void SendPicture(Image image)  override 
    {

        m_messagerExp->DrawShape();
        //........
    }
};



class MessagerPerfect :public IMessager {


public:

    virtual void Login(string username, string password)  override 
    {

        m_messagerExp->PlaySound();
        //********
        m_messagerExp->Connect();
        //........
    }
    virtual void SendMessage(string message) override 
    {

        m_messagerExp->PlaySound();
        //********
        m_messagerExp->WriteText();
        //........
    }
    virtual void SendPicture(Image image) override 
    {

        m_messagerExp->PlaySound();
        //********
        m_messagerExp->DrawShape();
        //........
    }
};
