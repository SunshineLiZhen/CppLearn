#include "stdafx.h"
#include "DATaTypeLearn.h"
#include "stdlib.h"
using namespace std;

DATaTypeLearn::DATaTypeLearn()
{
}


DATaTypeLearn::~DATaTypeLearn()
{
}

void DATaTypeLearn::yinYongExample()
{
	int sun = 0;
	//��������
	int & xingXing = sun;

	//ͨ���������޸ı���ֵ
	sun = 4;
	cout << "sun =" << sun << endl;

	// ͨ�������޸ı���ֵ
	xingXing = 6;
	cout << "sun = " << xingXing << endl;

}

void DATaTypeLearn::asXingCan(int &x, int &y)
{
	//ͨ�������β�ֱ�ӿ����޸�ԭֵ����ָ��Ĺ��ܲ��ұ���ָ�������Ķ�
	int c = 0;
	c = x;
	x = y;
	y = c;


	//ָ�������  �����β�Ϊ*a,*b
	//c = *a;
	//*a = *b;
	//*b = c;
	
}

void DATaTypeLearn::typeConvertExample()
{
	// static_cast
	char c = 55;
	int *p = (int*)(&c);//����ʱ�޴룬����ʱ�д�
	//cout << (char)*p << endl;
	
	//*p = 5;
	//int *q = static_cast<int*>(&c);//�������

	int ii = 10;
	float ff = 20.0;
	ii = static_cast<int>(ff);
	A* a = new A;
	B* b = new B;
	C* cc = NULL;

	a = dynamic_cast<A*>(b);
	if (NULL == a)
	{
		cout << "aFial" << endl;
	}
	else
	{
		a->test();
	}
	// ����ʱ�޴�
	b = static_cast<B*>(a);
	b = dynamic_cast<B*>(a);
	
	if (NULL != b)
	{
		b->bOnly();
		b->test();//����ת��ʧ��
	}
	else
	{
		cout << "fail" << endl;
	}
	system("pause");
	//cc = (C*)(a);
	// cc = static_cast<C*>(a);// error �������
}


