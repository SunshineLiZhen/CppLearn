#pragma once
#include <iostream>
#include "IMessagerExpand.hpp"
using namespace std;

class Image
{

};

/// <summary>
/// 信息发送者接口类
/// </summary>
class IMessager
{
protected:
    shared_ptr<IMessagerExpand> m_messagerExp = nullptr;

public:
    /// <summary>
    /// 登录操作
    /// </summary>
    /// <param name="username">用户名</param>
    /// <param name="password">密码</param>
    virtual void Login(string username, string password) = 0;

    /// <summary>
    /// 发送信息
    /// </summary>
    /// <param name="message"></param>
    virtual void SendMessage(string message) = 0;

    /// <summary>
    /// 发送图片
    /// </summary>
    /// <param name="image"></param>
    virtual void SendPicture(Image image) = 0;

    virtual ~IMessager() {}
};


