#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// 流操作接口类
/// </summary>
class IStream
{
public:
   
    /// <summary>
    /// 读文件流
    /// </summary>
    /// <param name="number">位置</param>
    /// <returns></returns>
    virtual char  Read(int number) = 0;

    /// <summary>
    /// 写文件流
    /// </summary>
    /// <param name="data">内容</param>
    virtual void  Write(char data) = 0;

    /// <summary>
    /// 定位文件流
    /// </summary>
    /// <param name="position">位置</param>
    virtual void Seek(int position) = 0;
};


