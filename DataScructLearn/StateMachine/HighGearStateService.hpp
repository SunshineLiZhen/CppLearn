#pragma once
#include <iostream>
#include "StateBase.hpp"

using namespace std;

class HighGearStateService :public StateBase
{
public:
	HighGearStateService()
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
		cout << "高档运行中..." << endl;
	}


};