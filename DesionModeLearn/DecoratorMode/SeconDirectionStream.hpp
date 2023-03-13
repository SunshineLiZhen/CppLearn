#pragma once
#include <iostream>
#include "DecoratorStream.hpp"

using namespace std;

/// <summary>
/// ������
/// </summary>
class CryptoStream :public DecoratorStream
{
public:
    CryptoStream(shared_ptr<IStream> stream) :DecoratorStream(stream)
    {

    }

    virtual char Read(int number) override
    {
        //����ļ��ܲ���...
        m_stream->Read(number);//���ļ���
   }

    virtual void Seek(int position) override
    {
        //����ļ��ܲ���...
        m_stream->Seek(position);//���ļ���
    }

    virtual void Write(char data) override
    {
        //����ļ��ܲ���...
        m_stream->Write(data);//���ļ���
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
        m_stream->Read(number);//���ļ���
    }

    virtual void Seek(int position) override
    {
        //...
        m_stream->Seek(position);//���ļ���
    }

    virtual void Write(char data) override
    {
        //...
        m_stream->Write(data);//���ļ���
    }
};
