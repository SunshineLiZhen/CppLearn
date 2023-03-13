#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// �ָ�����Ʒ������
/// </summary>
class ISplitter
{
public:
    virtual void  Split(string str) = 0;

    virtual ~ISplitter() {}
};


/// <summary>
/// �������ļ��ָ���
/// </summary>
class BinarySplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
};

/// <summary>
/// �ı��ļ��ָ���
/// </summary>
class TxtSplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
};


/// <summary>
/// ͼƬ�ָ���
/// </summary>
class PictureSplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
}; 

/// <summary>
/// ��Ƶ�ָ���
/// </summary>
class VideoSplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
};