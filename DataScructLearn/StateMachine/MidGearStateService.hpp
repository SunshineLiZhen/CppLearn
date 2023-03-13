#pragma once
#include <iostream>
#include "StateBase.hpp"

using namespace std;

class MidGearStateService :public StateBase
{
public:
	MidGearStateService()
	{

	}

	void Enter() override
	{

	}

	void Exit() override
	{

	}

	void Work() override
	{
		cout << "中档运行中..." << endl;
	}


};