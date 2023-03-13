#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// ��Ϣ��������չ
/// </summary>
class IMessagerExpand
{
public:
    /// <summary>
    /// ��������
    /// </summary>
    virtual void PlaySound() = 0;

    /// <summary>
    /// ����״
    /// </summary>
    virtual void DrawShape() = 0;

    /// <summary>
    /// д�ı�
    /// </summary>
    virtual void WriteText() = 0;

    /// <summary>
    /// ����
    /// </summary>
    virtual void Connect() = 0;

    virtual ~IMessagerExpand() {}

};




