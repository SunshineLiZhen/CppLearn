#pragma once
#include <iostream>
#include "IStream.hpp"
using namespace std;


class FileStream : public IStream
{
public:
    virtual char Read(int number) {
        //���ļ���
    }
    virtual void Seek(int position) {
        //��λ�ļ���
    }
    virtual void Write(char data) {
        //д�ļ���
    }
};

class NetworkStream : public IStream
{
public:
    virtual char Read(int number) {
        //���ļ���
    }
    virtual void Seek(int position) {
        //��λ�ļ���
    }
    virtual void Write(char data) {
        //д�ļ���
    }
};

class MemoryStream : public IStream
{
public:
    virtual char Read(int number) {
        //���ļ���
    }
    virtual void Seek(int position) {
        //��λ�ļ���
    }
    virtual void Write(char data) {
        //д�ļ���
    }
};
