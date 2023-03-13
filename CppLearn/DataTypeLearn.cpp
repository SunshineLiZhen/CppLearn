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
	//定义引用
	int & xingXing = sun;

	//通过变量名修改变量值
	sun = 4;
	cout << "sun =" << sun << endl;

	// 通过引用修改变量值
	xingXing = 6;
	cout << "sun = " << xingXing << endl;

}

void DATaTypeLearn::asXingCan(int &x, int &y)
{
	//通过引用形参直接可以修改原值，有指针的功能并且比用指针容易阅读
	int c = 0;
	c = x;
	x = y;
	y = c;


	//指针的形势  加入形参为*a,*b
	//c = *a;
	//*a = *b;
	//*b = c;
	
}

void DATaTypeLearn::typeConvertExample()
{
	// static_cast
	char c = 55;
	int *p = (int*)(&c);//编译时无措，运行时有错
	//cout << (char)*p << endl;
	
	//*p = 5;
	//int *q = static_cast<int*>(&c);//编译错误

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
	// 编译时无错
	b = static_cast<B*>(a);
	b = dynamic_cast<B*>(a);
	
	if (NULL != b)
	{
		b->bOnly();
		b->test();//向下转换失败
	}
	else
	{
		cout << "fail" << endl;
	}
	system("pause");
	//cc = (C*)(a);
	// cc = static_cast<C*>(a);// error 编译错误
}


