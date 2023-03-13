#pragma once
#include <iostream>

using namespace std;

/// <summary>
/// �������ӿ���
/// </summary>
class IStream
{
public:
   
    /// <summary>
    /// ���ļ���
    /// </summary>
    /// <param name="number">λ��</param>
    /// <returns></returns>
    virtual char  Read(int number) = 0;

    /// <summary>
    /// д�ļ���
    /// </summary>
    /// <param name="data">����</param>
    virtual void  Write(char data) = 0;

    /// <summary>
    /// ��λ�ļ���
    /// </summary>
    /// <param name="position">λ��</param>
    virtual void Seek(int position) = 0;
};


