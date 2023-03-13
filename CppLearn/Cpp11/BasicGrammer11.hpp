#pragma once
#include <iostream>

using namespace std;

class BasicGrammer11
{
public:
	void test()
	{
		cout << "decltypeLearn" << endl;
		decltypeLearn();
	}

	void decltypeLearn()
	{
		int a = 10;
		int b = 20;
		auto c = a + b;

		cout << typeid(c).name() << endl;
	}

	
};