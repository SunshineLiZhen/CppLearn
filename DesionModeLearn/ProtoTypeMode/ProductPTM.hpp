#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// 分割器产品抽象类
/// </summary>
class ISplitterPTM
{
public:
    virtual void  Split(string str) = 0;

    virtual shared_ptr<ISplitterPTM> Clone() = 0;

    virtual ~ISplitterPTM() {}
};

/// <summary>
/// 二进制文件分割器
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
/// 文本文件分割器
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
/// 图片分割器
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
/// 视频分割器
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