#pragma once
#include <iostream>
#include "IMessagerExpand.hpp"
using namespace std;

class Image
{

};

/// <summary>
/// ��Ϣ�����߽ӿ���
/// </summary>
class IMessager
{
protected:
    shared_ptr<IMessagerExpand> m_messagerExp = nullptr;

public:
    /// <summary>
    /// ��¼����
    /// </summary>
    /// <param name="username">�û���</param>
    /// <param name="password">����</param>
    virtual void Login(string username, string password) = 0;

    /// <summary>
    /// ������Ϣ
    /// </summary>
    /// <param name="message"></param>
    virtual void SendMessage(string message) = 0;

    /// <summary>
    /// ����ͼƬ
    /// </summary>
    /// <param name="image"></param>
    virtual void SendPicture(Image image) = 0;

    virtual ~IMessager() {}
};


