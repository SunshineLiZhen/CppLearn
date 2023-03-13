#pragma once

#include <iostream>

using namespace std;




class BaseClassV
{
public:
	virtual void PrintName() {}
};


class ChildClassV :public BaseClassV
{
private:
	int m_type;
public:
	void SetName(int type)
	{
		m_type = type;
	}

	void PrintName() override
	{
		cout << "My name is " << m_type << endl;
	}
};

class BV2
{
public:
	BV2() = default;
};

class CV2:public BV2
{
public:
	virtual void PrintName() {}
};

class CV3 :public CV2
{
public:

};

/// �麯��������
class VirtualFunctionLearn
{
public:
	void Test()
	{
		// ������Ĵ�С
		// ������Ҳ���麯����ָ��
		cout << "�����С��" << sizeof(BaseClassV) << endl;// 8���ֽ�
		cout << "�����С" << sizeof(ChildClassV) << endl; // 16���ֽ�

		// ����BV2��û��virtual����������û���麯��ָ��
		cout << "�����С��" << sizeof(BV2) << endl;// 1���ֽ�
		cout << "�����С" << sizeof(CV2) << endl; // 8���ֽ�
		cout << "�����С" << sizeof(CV3) << endl; // 8���ֽ�

		BaseClassV bv1;
		ChildClassV cA1, cA2;
		cA1.SetName(1);
		cA2.SetName(2);

		// ÿ�������麯�����඼��һ���麯��������BaseClassV��һ����������ChildClassVҲ��һ�������߲���һ����
		cout << *((int*)(&bv1)) << endl;//1418468736
		cout << *((int*)(&cA1)) << endl;//1418468760
		cout << *((int*)(&cA2)) << endl;//1418468760

		BaseClassV* pB = &cA1;
		pB->PrintName();
		pB = &cA2;
		pB->PrintName();
	}

};