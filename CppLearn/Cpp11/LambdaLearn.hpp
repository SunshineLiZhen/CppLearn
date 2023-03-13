#pragma once
#include <chrono>

using namespace std;

class LambdaLearn
{
public:
	void Test()
	{
		int x;
		auto tmp = [](int a) {return 3 +a; };
		tmp(x);
		//x = [&] {return 3; };
	}

};

