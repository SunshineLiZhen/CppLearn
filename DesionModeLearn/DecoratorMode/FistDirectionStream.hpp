#pragma once
#include <iostream>
#include "IStream.hpp"
using namespace std;


class FileStream : public IStream
{
public:
    virtual char Read(int number) {
        //读文件流
    }
    virtual void Seek(int position) {
        //定位文件流
    }
    virtual void Write(char data) {
        //写文件流
    }
};

class NetworkStream : public IStream
{
public:
    virtual char Read(int number) {
        //读文件流
    }
    virtual void Seek(int position) {
        //定位文件流
    }
    virtual void Write(char data) {
        //写文件流
    }
};

class MemoryStream : public IStream
{
public:
    virtual char Read(int number) {
        //读文件流
    }
    virtual void Seek(int position) {
        //定位文件流
    }
    virtual void Write(char data) {
        //写文件流
    }
};
