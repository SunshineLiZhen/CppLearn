#pragma once

using namespace std;


class FunctionLearn
{
public:
	FunctionLearn();
	~FunctionLearn();

	// 函数的默认值，最右边的必须有，不允许右边没有
	void FunDeafultValue(int x, int y=10, int z=20);
	//void FunDeafultValue(int x, int y = 10, int z); //这样不行，编译不过

	//函数重载
};

