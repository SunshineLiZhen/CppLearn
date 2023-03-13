#pragma once
class STLLearn
{
public:
	STLLearn();
	~STLLearn();

	void vectorExample();
	void mapExample();
	// 函数对象学习
	void functionalExample();
};

class VectorLearn
{

};

//函数对象学习
class MultClass
{
public:
	int operator()(int x,int y)
	{
		return x*y;
	}
};
class FunctionObjectLearn
{
public:

};

