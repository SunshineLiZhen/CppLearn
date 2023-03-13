#pragma once
#include <iostream>
#include "StateBase.hpp"

using namespace std;

class LowGearStateService :public StateBase
{
public:
	LowGearStateService()
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
		cout << "µÍµµÔËÐÐÖÐ..." << endl;
	}


};