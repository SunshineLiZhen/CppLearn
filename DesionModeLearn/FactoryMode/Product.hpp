#pragma once
#include <iostream>


using namespace std;

/// <summary>
/// 分割器产品抽象类
/// </summary>
class ISplitter
{
public:
    virtual void  Split(string str) = 0;

    virtual ~ISplitter() {}
};


/// <summary>
/// 二进制文件分割器
/// </summary>
class BinarySplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
};

/// <summary>
/// 文本文件分割器
/// </summary>
class TxtSplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
};


/// <summary>
/// 图片分割器
/// </summary>
class PictureSplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
}; 

/// <summary>
/// 视频分割器
/// </summary>
class VideoSplitter :public ISplitter
{
public:
    virtual void Split(string str) override
    {

    }
};