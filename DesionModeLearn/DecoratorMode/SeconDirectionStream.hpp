#pragma once
#include <iostream>
#include "DecoratorStream.hpp"

using namespace std;

/// <summary>
/// 加密流
/// </summary>
class CryptoStream :public DecoratorStream
{
public:
    CryptoStream(shared_ptr<IStream> stream) :DecoratorStream(stream)
    {

    }

    virtual char Read(int number) override
    {
        //额外的加密操作...
        m_stream->Read(number);//读文件流
   }

    virtual void Seek(int position) override
    {
        //额外的加密操作...
        m_stream->Seek(position);//读文件流
    }

    virtual void Write(char data) override
    {
        //额外的加密操作...
        m_stream->Write(data);//读文件流
    }
};



class BufferedStream :public DecoratorStream
{
public:
    BufferedStream(shared_ptr<IStream> stream) :DecoratorStream(stream)
    {

    }

    virtual char Read(int number) override
    {
        //...
        m_stream->Read(number);//读文件流
    }

    virtual void Seek(int position) override
    {
        //...
        m_stream->Seek(position);//读文件流
    }

    virtual void Write(char data) override
    {
        //...
        m_stream->Write(data);//读文件流
    }
};
