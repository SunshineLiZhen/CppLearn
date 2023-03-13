#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// 消息发送者扩展
/// </summary>
class IMessagerExpand
{
public:
    /// <summary>
    /// 播放音乐
    /// </summary>
    virtual void PlaySound() = 0;

    /// <summary>
    /// 画形状
    /// </summary>
    virtual void DrawShape() = 0;

    /// <summary>
    /// 写文本
    /// </summary>
    virtual void WriteText() = 0;

    /// <summary>
    /// 连接
    /// </summary>
    virtual void Connect() = 0;

    virtual ~IMessagerExpand() {}

};




