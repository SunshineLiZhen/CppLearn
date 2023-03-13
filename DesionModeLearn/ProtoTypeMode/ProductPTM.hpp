#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// �ָ�����Ʒ������
/// </summary>
class ISplitterPTM
{
public:
    virtual void  Split(string str) = 0;

    virtual shared_ptr<ISplitterPTM> Clone() = 0;

    virtual ~ISplitterPTM() {}
};

/// <summary>
/// �������ļ��ָ���
/// </summary>
class BinarySplitter :public ISplitterPTM
{
public:
    virtual void Split(string str) override
    {

    }

    virtual shared_ptr<ISplitterPTM> Clone()
    {
        return make_shared< BinarySplitter>(*this);
    }

};

/// <summary>
/// �ı��ļ��ָ���
/// </summary>
class TxtSplitter :public ISplitterPTM
{
public:
    virtual void Split(string str) override
    {

    }

    virtual shared_ptr<ISplitterPTM> Clone()
    {
        return make_shared< TxtSplitter>(*this);
    }

};


/// <summary>
/// ͼƬ�ָ���
/// </summary>
class PictureSplitter :public ISplitterPTM
{
public:
    virtual void Split(string str) override
    {

    }

    virtual shared_ptr<ISplitterPTM> Clone()
    {
        return make_shared< PictureSplitter>(*this);
    }
};

/// <summary>
/// ��Ƶ�ָ���
/// </summary>
class VideoSplitter :public ISplitterPTM
{
public:
    virtual void Split(string str) override
    {

    }

    virtual shared_ptr<ISplitterPTM> Clone()
    {
        return make_shared< VideoSplitter>(*this);
    }
};